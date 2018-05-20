#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
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
typedef pair<ll, ll> P;
struct edge{ll u, v ; ll cost; };
int V, E;
int N;
vector<edge> es;
vector<P> vx, vy;
ll llabs(ll x){
  return x >= 0 ? x : - x;
}

// union - find tree !!!!!!!!!!!!!!!!!!!!!!!!!
vector<int> par; //oya
vector<int> rnk; //ki no hu ka sa
// n要素で初期化
void init(int n){
    par.resize(n);rnk.resize(n);
    FOR(i, 0, n){par[i] = i;rnk[i] = 0;}
}
//木の根を求める
int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}
//xとyの属する集合を併合
void unite(int x, int y){
    x = find(x);y = find(y);
    if(x == y) return;
    if(rnk[x] < rnk[y])par[x] = y;
    else{par[y] = x;if(rnk[x] == rnk[y]) rnk[x]++;}
    return;
}
bool isSame(int x, int y){return find(x) == find(y);}

ll kruskal(){
  sort(es.begin(), es.end(), [](edge& e1, edge& e2){
    return e1.cost < e2.cost;
  });
  init(V);
  ll res = 0;
  FOR(i,0,E){
    edge e = es[i];
    if(!isSame(e.u, e.v)){
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

int main(){
  cin >> N;
  vx.resize(N);
  vy.resize(N);
  es.resize(2*(N-1));
  FOR(i,0,N)
  {
    ll x, y;
    cin >> x >> y;
    vx[i] = P(x,i);
    vy[i] = P(y,i);
  }
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  FOR(i,0,N-1)
  {
    edge e;
    e.u = vx[i+1].second;
    e.v = vx[i].second;
    e.cost = vx[i+1].first - vx[i].first;
    es[2 * i] = e;
  }
  FOR(i,0,N-1)
  {
    edge e;
    e.u = vy[i+1].second;
    e.v = vy[i].second;
    e.cost = vy[i+1].first - vy[i].first;
    es[2 * i + 1] = e;
  }
  V = N;
  E = 2 * (N - 1);
  ll ans = kruskal();
  cout << ans << endl;
  return 0;
}
