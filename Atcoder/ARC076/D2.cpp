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
typedef pair<int, int> P;
int N;
struct edge {
  ll u, v, cost;
  edge(ll a, ll b, ll c) {
    u = a, v = b, cost = c;
  }
};
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

// クラスカル法(最小全域木求めるやつ)
bool comp(edge& e1, edge& e2){
  return e1.cost < e2.cost;
}

vector<edge> es;
ll kruskal(){
  sort(es.begin(), es.end(), comp);
  init(N);
  ll res = 0;
  FOR(i,0,es.size()){
    edge e = es[i];
    if(!isSame(e.u, e.v)){
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  vector<P> x(N), y(N);
  FOR(i,0,N) {
    int xx, yy; cin >> xx >> yy;
    x[i] = P(xx, i);
    y[i] = P(yy, i);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  FOR(i,0,N-1) {
    es.push_back(edge(x[i].second, x[i+1].second, abs(x[i].first - x[i+1].first)));
    es.push_back(edge(y[i].second, y[i+1].second, abs(y[i].first - y[i+1].first)));
  }
  cout << kruskal() << endl;
  return 0;
}