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

//方針(答え見た)
//dp[j][k][s]:=1~jまいめのカードの中でk枚使ってsにできる総数

ll dp[51][51][3000];
ll x[50];
int main(){
    ll N,A;
    cin>>N>>A;
    FOR(i, 0, N) cin>>x[i];
    FOR(i, 0, 51) FOR(j, 0, 51) FOR(k, 0, 3000) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    FOR(i, 0, N){
        FOR(j, 0, N){
            FOR(k, 0, 3000){
                if(dp[i][j][k]==0) continue;
                //使う
                dp[i+1][j+1][k+x[i]] += dp[i][j][k];
                //使わない
                dp[i+1][j][k] += dp[i][j][k];
            }
        }
    }
    ll ans = 0;
    //答えはdp[N][j][jA]
    FOR(j, 1, N+1){
        ans += dp[N][j][j*A];
    }
    cout << ans << endl;
}
