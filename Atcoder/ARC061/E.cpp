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
const int inf = 1e9;
typedef pair<int, int> P;
// ダイクストラO(elogv)
struct edge{
  int to, cost;
  edge(int t, int c) {
    to = t, cost = c;
  }
};
int N, M;
vector<edge> G[603030];
int d[603030];
map<P, int> ID;
int maxid;
int PP[200005], Q[200005], C[200005];
void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P> >que;
  FOR(i,0,maxid+N+1) d[i] = inf;
  d[s] = 0;
  que.push(P(0, s));
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(auto &e : G[v]){
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}
int getid(int a, int b) {
  if(ID.count(P(a, b))) return ID[P(a, b)];
  return ID[P(a, b)] = maxid++;
}
// 同じ路線をつなぐ
void addEdge(int p, int q, int c) {
  int id1 = getid(p, c);
  int id2 = getid(q, c);
  G[id1].push_back(edge(id2, 0));
  G[id2].push_back(edge(id1, 0));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  FOR(i,0,M) {
    cin >> PP[i] >> Q[i] >> C[i];
    addEdge(PP[i], Q[i], C[i]);
  }
  // 駅〜改札まではコスト1
  FOR(i,0,M) {
    G[ID[P(PP[i], C[i])]].push_back(edge(maxid + PP[i], 1));
    G[maxid + PP[i]].push_back(edge(ID[P(PP[i], C[i])], 1));
    G[ID[P(Q[i], C[i])]].push_back(edge(maxid + Q[i], 1));
    G[maxid + Q[i]].push_back(edge(ID[P(Q[i], C[i])], 1));
  }
  dijkstra(maxid + 1);
  cout << (d[maxid + N] == inf ? -1 : d[maxid + N] / 2) << endl;
  return 0;
}