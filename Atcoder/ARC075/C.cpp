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

#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

typedef long long ll;

int main(){
    int N;
    cin >> N;
    int s[N];
    FOR(i,0,N) cin >> s[i];
    bool dp[N+1][10001];
    FOR(i,0,N+1)FOR(j,0,10001)dp[i][j] = false;
    dp[0][0] = true;
    FOR(i,0,N){
        FOR(j,0,10001){
            if(!dp[i][j]) continue;
            //if((j+s[i]) % 10 == 0) dp[i+1][0] = true;
            dp[i+1][j+s[i]] = true;
            dp[i+1][j] = true;
        }
    }
    int ans = 0;
    FOR(i,0,10001){
        if(dp[N][i]){
            if(i%10!=0) ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
