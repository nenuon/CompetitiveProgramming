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
#define CLR(mat) memset(mat, -1, sizeof(mat))
typedef long long ll;
int N, Z, W;
int a[2222];
int memo[2222][2222][2];
int dp_a[2222], dp_b[2222];
// who -> 1 aが下
int dfs(int ai, int bi, int who) {
  if(memo[ai][bi][who] != -1) return memo[ai][bi][who];
  if(ai == N - 1 || bi == N - 1) return memo[ai][bi][who] = abs(a[ai] - a[bi]);
  if(who == 1) {
    int ret = 1e9;
    if(dp_a[ai] != -1) return memo[ai][bi][who] = dp_a[ai];
    for(int i = N - 1; i > ai; i--) {
      ret = min(ret, dfs(ai, i, -who));
    }
    dp_a[ai] = ret;
    return memo[ai][bi][who] = ret;
  } else {
    int ret = -1e9;
    if(dp_b[bi] != -1) return memo[ai][bi][who] = dp_b[bi];
    for(int i = N - 1; i > bi; i--) {
      ret = max(ret, dfs(i, bi, -who));
    }
    dp_b[bi] = ret;
    return memo[ai][bi][who] = ret;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Z >> W;
  FOR(i,2,N+2) cin >> a[i];
  a[0] = Z;
  a[1] = W;
  N += 2;
  CLR(memo);
  CLR(dp_a);
  CLR(dp_b);
  dp_a[N-1] = abs(a[N-1] - W);
  int ans = dfs(0,1,-1);
  cout << ans << endl;
}