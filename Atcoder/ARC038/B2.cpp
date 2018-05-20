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
int H, W;
vector<string> vs(100);
// falseが帰ってきたらかち
int memo[111][111][2];
bool dfs(int h, int w, bool who) {
  if(memo[h][w][who] != -1) return memo[h][w][who];
  if(h < 0 || h >= H || w < 0 || w >= W) return false;
  if(vs[h][w] == '#') return false;
  bool ret = false;
  ret |= dfs(h, w + 1, who^1);
  ret |= dfs(h + 1, w + 1, who^1);
  ret |= dfs(h + 1, w, who^1);
  return memo[h][w][who] = ret^1;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W;
  FOR(i,0,H) {
    cin >> vs[i];
  }
  FOR(i,0,H+1) FOR(j,0,W+1) FOR(k,0,2) memo[i][j][k] = -1;
  if(!dfs(0, 0, 0)) cout << "First" << endl;
  else cout << "Second" << endl;
  return 0;
}