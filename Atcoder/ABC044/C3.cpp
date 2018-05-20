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

//使う使わないの2パターンのみ

ll dp[60][60][3000];
ll N,A;
int main(){
    cin>>N>>A;
    FOR(i, 0, 60) FOR(j, 0, 60) FOR(k, 0, 3000) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    FOR(i, 0, N){
        int x;cin>>x;
        FOR(j, 0, N){
            FOR(k, 0, N*50+1){
                if(dp[i][j][k]==0) continue;
                //使わない場合
                dp[i+1][j][k] += dp[i][j][k];
                //使う場合
                if(k+x>N*50) continue;
                dp[i+1][j+1][k+x] += dp[i][j][k];
            }
        }
    }
    ll ans = 0;
    FOR(i, 1, N+1){
        ans += dp[N][i][i*A];
    }
    cout << ans << endl;
}
