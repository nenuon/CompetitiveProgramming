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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M, S; cin >> N >> M >> S;
  vector<P> v(M);
  FOR(i,0,M) {
    int a, b; cin >> a >> b;
    v[i] = P(min(a, b), max(a, b));
  }
  sort(v.rbegin(), v.rend());
  init(N+1);
  vector<int> ans;
  ans.push_back(S);
  int j = 0;
  for(int i = S - 1; i >= 1; i--) {
    while(j < M && v[j].first >= i) {
      unite(v[j].first, v[j].second);
      j++;
    }
    if(isSame(S, i)) ans.push_back(i);
  }
  reverse(ans.begin(), ans.end());
  FOR(i,0,ans.size()) cout << ans[i] << endl;
}
