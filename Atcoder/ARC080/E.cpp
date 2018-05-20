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
typedef pair<int, int> pint;

const int INF = 1000000000;
struct segtree {
  vector<pint> dat; // 値、位置
  static const int N = 1 << 18;
  segtree() : dat(N * 2, pint(INF, -1)){}
  void init(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) dat[i+N-1] = {v[i], i};
    for(int i = N - 2; i >= 0; i--) dat[i] = min(dat[i*2+1], dat[i*2+2]);
  }
  pint get_min(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) return pint(INF, -1);
    if(a <= l && r <= b) return dat[k];
    return min(get_min(a,b,k*2+1,l,(l+r)/2),get_min(a,b,k*2+2,(l+r)/2,r));
  }
  pint get_min(int a, int b) {
    return get_min(a,b,0,0,N);
  }
};

int N;
int P[222222];

segtree odd, even; // 偶数番目と機数番目用

int cur;
vector<int> G[222222];
pint val[222222];

// [l, r)の区間の最小のペア
void solve(int l, int r) {
  int x, y;
  // 区間の開始が全体の区間の偶数番目の場合
  if(l % 2 == 0) {
    x = even.get_min(l, r).second;
    y = odd.get_min(x + 1, r).second;
  } else {
    x = odd.get_min(l, r).second;
    y = even.get_min(x + 1, r).second;
  }

  val[cur] = {P[x], P[y]};

  int v = cur;
  cur++;
  if(x != l) {
    G[v].push_back(cur);
    solve(l, x);
  }
  if(x + 1 != y) {
    G[v].push_back(cur);
    solve(x+1, y);
  }
  if(y != r - 1) {
    G[v].push_back(cur);
    solve(y+1, r);
  }
}

struct data{
  pint p;
  int k;
  data(pint p, int k):p(p), k(k){}
};

bool operator < (const data &a, const data &b) {
  return a.p > b.p;
}

int main()
{
  cin >> N;
  FOR(i,0,N) cin >> P[i];

  vector<int> latte(N);
  FOR(i,0,N) {
    if(i % 2 == 0) latte[i] = P[i];
    else latte[i] = INF;
  }
  even.init(latte);

  FOR(i,0,N) {
    if(i % 2 == 1) latte[i] = P[i];
    else latte[i] = INF;
  }
  odd.init(latte);

  solve(0, N);
  priority_queue<data> que;
  que.push(data(val[0], 0));
  vector<int> ans;
  while(!que.empty()) {
    pint p = que.top().p;
    int k = que.top().k;
    que.pop();
    ans.push_back(p.first);
    ans.push_back(p.second);
    for(auto ad : G[k]) {
      que.push(data(val[ad], ad));
    }
  }
  FOR(i,0,N) {
    printf("%d%c",ans[i],i==N-1?'\n':' ');
  }
  return 0;
}
