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
    ll MOD = pow(10, 9) + 7;
    int n, m;
    cin>>n>>m;
    ll x[n], y[m];
    FOR(i, 0, n) cin>>x[i];
    FOR(i, 0, m) cin>>y[i];
    ll x_times = 0, y_times = 0;
    FOR(i, 1, n+1){
        x_times += (i-1)*x[i-1] - (n-i)*x[i-1];
        x_times %= MOD;
    }
    FOR(i, 1, m+1){
        y_times += (i-1)*y[i-1] - (m-i)*y[i-1];
        y_times %= MOD;
    }
    ll ans = (x_times * y_times) % MOD;
    cout << ans << endl;
}
