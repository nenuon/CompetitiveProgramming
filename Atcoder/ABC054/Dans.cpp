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

#define pb         push_back
#define mp         make_pair
#define ll         long long
#define PI         acos(-1.0)
#define ALL(A)     ((A).begin(), (A).end())
#define vsort(v)   sort(v.begin(),v.end())
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;

    int a[N], b[N], c[N];
    FOR(i, 0, N) cin >> a[i] >> b[i] >> c[i];

    int abmax = 40 * 10;
    int dp[N+1][abmax+1][abmax+1];
    int INF = 100 * 40 * 10;
    FOR(i, 0, N+1){
        FOR(j, 0, abmax+1){
            FOR(k, 0, abmax+1){
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    FOR(i, 0, N){
        FOR(j, 0, abmax+1){
            FOR(k, 0, abmax+1){
                if(dp[i][j][k]==INF) continue;
                //nouse
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                //use
                dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
            }
        }
    }

    int ret = INF;
    FOR(j, 1, abmax+1){
        FOR(k, 1, abmax+1){
            if(Ma*k==Mb*j){
                ret = min(ret, dp[N][j][k]);
            }
        }
    }
    if(ret == INF) ret = -1;
    cout << ret << endl;
}