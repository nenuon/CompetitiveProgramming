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
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
const int inf = 1e9;
int dp[60][10010][60]; // 調べた枚数、幅, 枚数
int main()
{
  int W, N, K;
  cin >> W >> N >> K;
  int A[N], B[N];
  FOR(i,0,N) cin >> A[i] >> B[i];
  FOR(i,0,60) FOR(j,0,10010) FOR(k,0,60) dp[i][j][k] = -inf;
  dp[0][0][0] = 0;
  FOR(i,0,N) {
    FOR(j,0,10005) {
      FOR(k,0,60) {
        if(dp[i][j][k] == -inf) continue;
        // 使わない
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
        // 使う
        if(j + A[i] > 10000) continue;
        dp[i+1][j+A[i]][k+1] = max(dp[i+1][j+A[i]][k+1], dp[i][j][k] + B[i]);
      }
    }
  }
  int ans = 0;
  FOR(w,1,W+1) {
    FOR(k,1,K+1) {
      ans = max(ans, dp[N][w][k]);
    }
  }
  cout << ans << endl;
  return 0;
}
