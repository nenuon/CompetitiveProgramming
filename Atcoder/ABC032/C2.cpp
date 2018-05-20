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

ll dp[60][60][3000];
ll N,A;
ll x[60];

int main(){
    cin>>N>>A;
    FOR(i, 0, N) cin>>x[i];
    FOR(i, 0, 60) FOR(j, 0, 60) FOR(k, 0, 3000) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    FOR(i, 0, N){
        FOR(j, 0, N){
            FOR(k, 0, 3000){
                if(dp[i][j][k]==0) continue;
                //使わない時
                dp[i+1][j][k] += dp[i][j][k];
                //使う時
                dp[i+1][j+1][k+x[i]] += dp[i][j][k];
            }
        }
    }
    ll ans = 0;
    FOR(i, 1, N+1){
        ans += dp[N][i][i*A];
    }
    cout << ans << endl;
}
