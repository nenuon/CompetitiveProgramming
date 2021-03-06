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
#include <cstring>
#include <deque>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, K; cin >> N >> K;
  ll a[N+1]; CLR(a);
  ll sum = 0;
  FOR(i,0,N) {
    cin >> a[i+1];
    sum += a[i+1];
  }
  if(sum == K) {
    cout << 1 << endl;
    return 0;
  }
  ll S[N+1]; CLR(S);
  FOR(i,0,N) S[i+1] = S[i] + a[i+1];
  S[0] = 1; // 0除算を防ぐ 
  ll dp[N+1][N+1];
  FOR(i,0,N+1) FOR(j,0,N+1) dp[i][j] = 2e9;
  dp[0][0] = 0;
  FOR(i,0,N) {
    FOR(j,0,N) {
      if(dp[i][j] == 2e9) continue;
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      ll k = dp[i][j] * a[i+1] / S[i] + 1;
      if(k > a[i+1]) continue;
      dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + k);
    }
  }
  ll ans = 0;
  FOR(i,0,N+1) {
    if(dp[N][i] <= K) ans = i;
  }
  cout << ans << endl;
  return 0;
}