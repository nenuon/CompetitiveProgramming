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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s; cin >> s;
  int len = s.length();
  if(len > 1000) return 0;
  ll dp[len+1][2222]; FOR(i,0,len+1) FOR(j,0,2222) dp[i][j] = -1e9;
  dp[0][1111] = 0;
  FOR(i,0,len) {
    FOR(j,0,2222) {
      if(dp[i][j] == -1e9) continue;
      if(s[i] == 'M') {
        // 右
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
        // 左
        dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]);
      } else if(s[i] == '+') {
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + (j - 1111));
      } else {
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] - (j - 1111));
      }
    }
  }
  cout << dp[len][1111] << endl;
  return 0;
}