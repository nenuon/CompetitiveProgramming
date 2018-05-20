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
typedef pair<int, int> P;
// 部分点 - > 全探索
int N, G, E;
vector<vector<int> > g(111);
bool cango[111][111];
bool girl[111];
bool visited[111];
vector<P> vp;
// 到達できてしまった女の子の数
int dfs(int x) {
  int ret = girl[x];
  visited[x] = true;
  for(int to : g[x]) {
    if(!cango[x][to] || visited[to]) continue;
    ret += dfs(to);
  }
  return ret;
}

int main()
{
  cin >> N >> G >> E;
  if(E > 12) return 0;
  FOR(i,0,111) FOR(j,0,111) cango[i][j] = false;
  FOR(i,0,111) girl[i] = false;
  FOR(i,0,G) {
    int in; cin >> in;
    girl[in] = true;
  }
  FOR(i,0,E) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
    cango[a][b] = true;
    cango[b][a] = true;
    vp.push_back(P(a, b));
  }
  int ans = 1e9;
  FOR(i,0,1<<E) {
    int cnt = 0;
    FOR(i,0,111) visited[i] = false;
    FOR(j,0,E) {
      if((i>>j)&1) {
        cango[vp[j].first][vp[j].second] = false;
        cango[vp[j].second][vp[j].first] = false;
        cnt++;
      }
    }
    ans = min(ans, dfs(0) + cnt);
    // 戻す
    FOR(j,0,E) {
      if((i>>j)&1) {
        cango[vp[j].first][vp[j].second] = true;
        cango[vp[j].second][vp[j].first] = true;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
