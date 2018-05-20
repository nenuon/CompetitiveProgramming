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

int main(){
    int N, K;
    cin>>N>>K;
    ll a[N+1];
    ll sum = 0;
    a[0] = 0;
    FOR(i, 1, N+1){
        ll in;
        cin>>in;
        sum += in;
        a[i] = sum;
    }
    ll ans = 0;
    FOR(i, K, N+1){
        ans += a[i] - a[i-K];
    }
    cout << ans << endl;
}
