#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

//2個みて大きい添え字の方から優先的に食べていくO(N)

int main(void){
    int N;
    ll x;
    cin>>N>>x;
    ll a, b;
    cin>>a;
    ll ans = 0;
    FOR(i, 1, N){
        cin>>b;
        ll eat = a+b>x?a+b-x:0;
        ans += eat;
        a = b>eat?b-eat:0;
    }
    cout << ans << endl;
}
