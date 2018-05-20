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
int N, M;
int a[100005];
bool used[100005];
priority_queue<P, vector<P>, greater<P> > Q[100005]; // グループiについて、重み, 頂点番号
priority_queue<P, vector<P>, greater<P> > QALL; // 値、グループ

// union - find tree !!!!!!!!!!!!!!!!!!!!!!!!!
vector<int> par; //oya
vector<int> rnk; //ki no hu ka sa
// n要素で初期化
void init(int n){
    par.resize(n);
    rnk.resize(n);
    FOR(i, 0, n){par[i] = i;rnk[i] = 0;}
}
//木の根を求める
int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}
//xとyの属する集合を併合
void unite(int x, int y, int z){
    x = find(x);y = find(y);
    if(x == y) return;
    if(z == 0) {
      if(rnk[x] < rnk[y]) par[x] = y;
      else{
        par[y] = x;
        if(rnk[x] == rnk[y]) rnk[x]++;
      }
    }
    else if(z == 1) par[y] = x;
    else par[x] = y;
    return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  init(100005);
  FOR(i, 0, N) cin >> a[i];
  // グループ分け
  FOR(i,0,M) {
    int x, y;
    cin >> x >> y;
    unite(x, y, 0);
  }
  int numg = 0;
  set<int> SET;
  FOR(i,0,N) {
    int g = find(i);
    if(SET.count(g) == 0) {
      numg++;
      SET.insert(g);
    }
    Q[g].push(P(a[i], i));
    QALL.push(P(a[i], i));
  }
  int must = 2 * (numg - 1);
  if(must == 0) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  for(auto s : SET) {
    P p = Q[s].top();
    ans += p.first;
    used[p.second] = true;
    must--;
  }
  while(!QALL.empty()) {
    if(must == 0) {
      cout << ans << endl;
      return 0;
    }
    P p = QALL.top(); QALL.pop();
    if(used[p.second]) continue;
    ans += p.first;
    must--;
  }
  if(must == 0) cout << ans << endl;
  else cout << "Impossible" << endl;
  return 0;
}