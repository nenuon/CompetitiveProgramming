### 解法
頂点iから頂点jへまっすぐ進んだ時に宇宙線を浴びる時間を求める(全ての頂点のペア分でO(N^2))。
頂点iと頂点jの中心の距離をdとした時、頂点iと頂点jの距離をd=max(0, d-r[i]-r[j])としてグラフを作成する。
グラフを作成したらダイクストラで最短系を求める。

### コード

```:cpp
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
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
typedef pair<int, int> P;
typedef pair<double, int> Pd;
const ll inf = 1e15;
map<P,int> ID;
int N;
// ダイクストラO(elogv)
struct edge{
  int to;
  double cost;
  edge(int t, double c) {
    to = t, cost = c;
  }
};
vector<edge> G[1111];
double d[1111];
void dijkstra(int s){
  priority_queue<Pd, vector<Pd>, greater<Pd> >que;
  FOR(i,0,N+2) d[i] = inf;
  d[s] = 0.0;
  que.push(Pd(0.0, s));
  while(!que.empty()){
    Pd p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(auto &e : G[v]){
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(Pd(d[e.to], e.to));
      }
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  cin >> N;
  int x[N+2], y[N+2], r[N+2];
  x[0] = xs;
  y[0] = ys;
  r[0] = 0;
  x[N+1] = xt;
  y[N+1] = yt;
  r[N+1] = 0;
  FOR(i,0,N) cin >> x[i+1] >> y[i+1] >> r[i+1]; 
  FOR(i,0,N+2) ID[P(x[i], y[i])] = i;
  FOR(i,0,N+2) {
    FOR(j,i+1,N+2) {
      double d = sqrt((double)pow(x[i]-x[j], 2)+(double)pow(y[i]-y[j], 2));
      int id_i = ID[P(x[i], y[i])];
      int id_j = ID[P(x[j], y[j])];
      d = max(d - r[i] - r[j], 0.0);
      G[id_i].push_back(edge(id_j, d));
      G[id_j].push_back(edge(id_i, d));
    }
  }
  dijkstra(0);
  printf("%.12lf\n",  d[N+1]);
  return 0;
}
```