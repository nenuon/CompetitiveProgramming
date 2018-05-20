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
    int N, K;
    cin >> N >> K;
    vector<int> R;
    FOR(i, 0, N){
        int r;
        cin >> r;
        R.pb(r);
    }

    int ratemax = 4000 * N;
    double dp[N+1][ratemax+1];
    FOR(j, 0, N+1){
        FOR(k, 0, ratemax+1) dp[j][k] = -1;
    }
    FOR(i, 0, N+1){
        dp[i][0] = 0.0;
    }
    vsort(R);
    FOR(i, 0, N){
        FOR(k, 0, ratemax+1){
            if(dp[i][k]==-1) continue;
            //no watch
            dp[i+1][k] = max(dp[i+1][k], dp[i][k]);
            //watch
            dp[i+1][k+R[i]] = max(dp[i+1][k+R[i]], (dp[i][k]+(double)R[i])/2);
        }
    }
    int wa = 0;
    FOR(i, N-K, N){
        wa += R[i];
    }
    printf("%.09lf\n" ,dp[N][wa]);
}