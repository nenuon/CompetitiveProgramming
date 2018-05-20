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
const int MAX_LOG = 20;
vector<vector<int> > G(100005);
int root;

int parent[MAX_LOG][100005];
int depth[100005];

void dfs(int v, int par, int d) {
  parent[0][v] = par;
  depth[v] = d;
  for(auto &to : G[v]) {
    if(to == par) continue;
    dfs(to, v, d + 1);
  }
}

void init(int V) {
  dfs(root, -1, 0);
  // parentを初期化する
  FOR(k,0,MAX_LOG-1) {
    FOR(v,0,V) {
      if(parent[k][v] < 0) parent[k+1][v] = -1;
      else parent[k+1][v] = parent[k][parent[k][v]];
    }
  }
}

// uとvのLCAを求める
int lca(int u, int v) {
  // vの方が深いことにする
  if(depth[u] > depth[v]) swap(u, v);
  FOR(k,0,MAX_LOG) {
    if(((depth[v]-depth[u])>>k)&1) {
      v = parent[k][v];
    }
  }
  if(u == v) return u;
  // 二分探索
  for(int k = MAX_LOG - 1; k >= 0; k--) {
    if(parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

int main()
{
  int N; cin >> N;
  FOR(i,0,N-1) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  root = 1;
  init(N+1);
  int Q; cin >> Q;
  FOR(i,0,Q) {
    int a, b; cin >> a >> b;
    cout << depth[a] + depth[b] - 2 * depth[lca(a, b)] + 1 << '\n';
  }
  return 0;
}
