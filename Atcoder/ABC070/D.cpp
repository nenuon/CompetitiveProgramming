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
typedef pair<ll, ll> P;
const ll inf = 1e15;
struct edge{
  ll to, cost;
  edge(ll t, ll c) {
    to = t, cost = c;
  }
};
// Kからの距離を求めておく
int N;
vector<edge> G[100005];
ll d[100005];
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
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}
int main()
{
  cin >> N;
  FOR(i,0,N-1) {
    ll a, b, c;
    cin >> a >> b >> c;
    G[a].push_back(edge(b, c));
    G[b].push_back(edge(a, c));
  }
  int Q, K; cin >> Q >> K;
  // Kからの距離
  dijkstra(K);
  FOR(i,0,Q) {
    int x, y; cin >> x >> y;
    cout << d[x] + d[y] << endl;
  }
  return 0;
}
