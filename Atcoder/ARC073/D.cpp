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

//方針
//dp[i][何個入れたか][重さ-w1]
//dp[N+1][N+1][4*N+1]

int main(){
    int N;
    cin >> N;
    ll W, w[N], v[N];
    cin >> W;
    FOR(i, 0, N) cin >> w[i] >> v[i];
    ll w0 = w[0];
    FOR(i, 0, N) w[i] -= w0;
    ll dp[N+1][N+1][3*N+1];
    FOR(i, 0, N+1) FOR(j, 0, N+1) FOR(k, 0, 3*N+1) dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    FOR(i, 0, N){
        FOR(j, 0, i+1){
            FOR(k, 0, 3*N+1){
                if(dp[i][j][k]==-1) continue;
                //入れない
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                //入れる
                if(W >= k+j*w0) dp[i+1][j+1][k+w[i]] = max(dp[i][j][k] + v[i], dp[i+1][j+1][k+w[i]]);
            }
        }
    }
    ll ans = 0;
    FOR(i, 1, N+1){
        FOR(j, 1, i+1){
            FOR(k, 0, 3*N+1){
                ll cost = (ll)(k + (ll)j * w0);
                if(W >= cost) ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
}
