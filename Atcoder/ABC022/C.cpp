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
const int inf = 1e9;

// ダイクストラO(ElogV)
struct edge{
  int to, cost;
  edge(int t, int c) {
    to = t, cost = c;
  }
};
typedef pair<int, int> P;
int N, M;
vector<edge> G[333];
int d[333];
int jiko;
void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P> >que;
  FOR(i,1,N+1) d[i] = inf;
  d[s] = 0;
  que.push(P(0, s));
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(auto &e : G[v]){
      if(v == jiko && e.to == 1) continue;
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main()
{
  cin >> N >> M;
  int u[M], v[M], l[M];
  FOR(i,0,M) cin >> u[i] >> v[i] >> l[i];
  FOR(i,0,M) {
    G[u[i]].push_back(edge(v[i], l[i]));
    G[v[i]].push_back(edge(u[i], l[i]));
  }
  // スタートを1と繋がってるところからとする
  int ans = inf;
  for(auto &e : G[1]) {
    jiko = e.to;
    dijkstra(e.to);
    ans = min(ans, d[1] + e.cost);
  }
  cout << (ans == inf ? -1 : ans) << endl;
  return 0;
}
