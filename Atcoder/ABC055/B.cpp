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
#include <bitset>
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

ll MOD = pow(10,9)+7;

int main(){
    int N;cin>>N;
    ll ans = 1;
    FOR(i, 1, N+1) ans = (ans*i) % MOD;
    cout << ans << endl;
}
