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
// 最大流、最小カット!!!!
// フォード・ファルカーソン法
const int MAX_V = 110;
// 行き先、容量、逆辺
struct edge {
  int to, cap, rev;
  edge(int t, int c, int r) {
    to = t, cap = c, rev = r;
  }
};
vector<vector<edge> > G(MAX_V);
bool used[MAX_V];
// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
  G[from].push_back(edge(to, cap, G[to].size()));
  G[to].push_back(edge(from, 0, G[from].size()-1));
}
// 増加パスをdfsで探す
int dfs(int v, int t, int f) {
  if(v == t) return f;
  used[v] = true;
  for(edge &e : G[v]) {
    if(!used[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}
int max_flow(int s, int t) {
  int flow = 0;
  for(;;) {
    FOR(i,0,MAX_V) used[i] = 0;
    int f = dfs(s, t, 1e9);
    if(f == 0) return flow;
    flow += f;
  }
}
int main()
{
  int N, G, E;
  cin >> N >> G >> E;
  FOR(i,0,G) {
    int in;
    cin >> in;
    add_edge(in, 105, 1);
  }
  FOR(i,0,E) {
    int a, b;
    cin >> a >> b;
    add_edge(a, b, 1);
    add_edge(b, a, 1);
  }
  cout << max_flow(0, 105) << endl;
  return 0;
}
