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
// メモ化?
int H, W;
int memo[111][111]; // 1がかえってきたら勝ち -1は負け
vector<string> vs;
int dfs(int y, int x) {
  if(y >= H || x >= W || vs[y][x] == '#') {
    return memo[y][x] = 1;
  }
  if(memo[y][x] != 0) return memo[y][x];
  // -1がかえって着たら自分は勝てるということ
  if(dfs(y + 1, x) < 0) return memo[y][x] = 1;
  if(dfs(y, x + 1) < 0) return memo[y][x] = 1;
  if(dfs(y + 1, x + 1) < 0) return memo[y][x] = 1;
  return memo[y][x] = -1;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W;
  FOR(i,0,H) {
    string s; cin >> s;
    vs.push_back(s);
  }
  CLR(memo);
  if(dfs(0, 0) > 0) puts("First");
  else puts("Second");
  return 0;
}
