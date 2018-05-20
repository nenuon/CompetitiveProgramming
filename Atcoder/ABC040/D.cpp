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
typedef pair<int, P> PP;
// union - find tree !!!!!!!!!!!!!!!!!!!!!!!!!
vector<int> par; //oya
vector<int> rnk; //ki no hu ka sa
vector<int> num; // 行ける町の数
// n要素で初期化
void init(int n){
    par.resize(n);rnk.resize(n);num.resize(n);
    FOR(i, 0, n){par[i] = i;rnk[i] = 0;num[i]=1;}
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
    num[x] += num[y];
    num[y] = num[x];
    return;
}
bool isSame(int x, int y){return find(x) == find(y);}
int main()
{
  int N, M; cin >> N >> M;
  init(N+1);
  vector<PP> info(M);
  FOR(i,0,M) {
    int a, b, y; cin >> a >> b >> y;
    info[i] = PP(y, P(a, b));
  }
  sort(info.rbegin(), info.rend());

  int Q; cin >> Q;
  vector<PP> people(Q);
  FOR(i,0,Q) {
    int v, w; cin >> v >> w;
    people[i] = PP(w, P(v, i));
  }
  sort(people.rbegin(), people.rend());

  vector<int> ans(Q);
  // iの人が通れる道を連結する
  int j = 0;
  FOR(i,0,Q) {
    while(j < M && info[j].first > people[i].first) {
      unite(info[j].second.first,info[j].second.second);
      j++;
    }
    ans[people[i].second.second] = num[find(people[i].second.first)];
  }
  FOR(i,0,Q) {
    cout << ans[i] << '\n';
  }
  return 0;
}
