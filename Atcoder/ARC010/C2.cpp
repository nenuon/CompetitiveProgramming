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
  map<char, int> MAP;
  int n, m, Y, Z;
  cin >> n >> m >> Y >> Z;
  int p[m+1]; CLR(p);
  FOR(i,1,m+1) {
    string s;
    int in;
    cin >> s >> in;
    MAP[s[0]] = i;
    p[i] = in;
  }
  int b[n];
  string s; cin >> s;
  FOR(i,0,n) {
    b[i] = MAP[s[i]];
  }
  int dp[2][1<<m][m+1];
  FOR(i,0,n+1) FOR(j,0,1<<m) FOR(k,0,m+1) dp[i%2][j][k] = -1e9;
  dp[0][0][0] = 0;
  FOR(i,0,n) {
    FOR(j,0,1<<m) {
      FOR(k,0,m+1) {
        // 積む
        if(k == b[i]) dp[(i+1)%2][j][k] = max(dp[(i+1)%2][j][k], dp[i%2][j][k] + p[b[i]] + Y);
        else dp[(i+1)%2][j|(1<<(b[i]-1))][b[i]] = max(dp[(i+1)%2][j|(1<<(b[i]-1))][b[i]], dp[i%2][j][k] + p[b[i]]);
        // 積まない
        dp[(i+1)%2][j][k] = max(dp[(i+1)%2][j][k], dp[i%2][j][k]);
      }
    }
  }
  int ans = -1e9;
  FOR(j,0,1<<m) {
    int all = 0;
    FOR(i,0,m) if((j >> i) & 1) all++;
    FOR(k,0,m+1) {
      if(all == m) dp[n%2][j][k] += Z;
      ans = max(ans, dp[n%2][j][k]);
    }
  }
  cout << ans << endl;
  return 0;
}