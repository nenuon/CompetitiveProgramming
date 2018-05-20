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
const ll inf = 1e17;

// N+1を1として仮想的に作る => 1->1 == 1->N+1

// ダイクストラO()
struct edge{
  ll to, cost;
  edge(ll t, ll c) {
    to = t, cost = c;
  }
};
typedef pair<ll, ll> P;
ll N, M, T;
vector<edge> G1[100005];
vector<edge> G2[100005];
ll d[100005];
void dijkstra1(ll s){
  priority_queue<P, vector<P>, greater<P> >que;
  FOR(i,1,N+2) d[i] = inf;
  d[s] = 0LL;
  que.push(P(0LL, s));
  while(!que.empty()){
    P p = que.top(); que.pop();
    ll v = p.second;
    if(d[v] < p.first) continue;
    for(auto &e : G1[v]){
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}
void dijkstra2(ll s){
  priority_queue<P, vector<P>, greater<P> >que;
  FOR(i,1,N+2) d[i] = inf;
  d[s] = 0LL;
  que.push(P(0LL, s));
  while(!que.empty()){
    P p = que.top(); que.pop();
    ll v = p.second;
    if(d[v] < p.first) continue;
    for(auto &e : G2[v]){
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> T;
  ll A[N]; FOR(i,0,N) cin >> A[i];
  ll a, b, c;
  FOR(i,0,M){
    cin >> a >> b >> c;
    G1[a].push_back(edge(b, c));
    G2[b].push_back(edge(a, c)); // 逆
    if(b == 1) {
      G1[a].push_back(edge(N+1, c));
      G2[N+1].push_back(edge(a, c)); // 逆
    }
  }
  G1[1].push_back(edge(N+1, 0LL));
  G2[N+1].push_back(edge(1, 0LL));

  ll move[N+2]; CLR(move);
  dijkstra1(1);
  FOR(i,1,N+2) move[i] += d[i];
  dijkstra2(N+1);
  FOR(i,1,N+2) move[i] += d[i];
  ll ans = 0;
  // iでトレジャーハント
  FOR(i,1,N+1) {
    if(T < move[i]) continue;
    ans = max(ans, (T - move[i]) * A[i-1]);
  }
  cout << ans << endl;
  return 0;
}