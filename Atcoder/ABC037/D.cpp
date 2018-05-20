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
const int mod = 1e9 + 7;
int H, W;
int num[1010][1010];
ll dp[1010][1010];
int dfs(int y, int x) {
  if(dp[y][x] != -1) return dp[y][x];
  ll ret = 1;
  if(num[y][x]<num[y+1][x]) ret += dfs(y+1,x);
  if(num[y][x]<num[y-1][x]) ret += dfs(y-1,x);
  if(num[y][x]<num[y][x+1]) ret += dfs(y,x+1);
  if(num[y][x]<num[y][x-1]) ret += dfs(y,x-1);
  ret %= mod;
  return dp[y][x] = ret;
}

int main()
{
  cin >> H >> W;
  FOR(i,0,1010) FOR(j,0,1010) num[i][j] = 0;
  FOR(i,0,H) FOR(j,0,W) scanf("%d", &num[i+1][j+1]);
  FOR(i,0,1010) FOR(j,0,1010) dp[i][j] = -1;
  ll ans = 0;
  FOR(i,1,H+1) {
    FOR(j,1,W+1) {
      ans += dfs(i,j);
      ans %= mod;
    }
  }
  cout << ans << endl;
}
