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
  init(30);
  int N; cin >> N;
  string s,t;
  cin >> s >> t;
  ll ans = 1;
  // 未定100、固定1、なんでも良い9or10
  int cnt[26]; // グループの親の文字について何通りの数字があり得るか
  FOR(i,0,26) cnt[i] = 100;

  FOR(i,0,N) {
    if(isdigit(s[i]) && isdigit(t[i])) {
      continue;
    } else if(isdigit(s[i])) {
      // t[i]をs[i]に固定する
      cnt[find(t[i]-'A')] = 1;
    } else if(isdigit(t[i])) {
      // s[i]をt[i]に固定する
      cnt[find(s[i]-'A')] = 1;
    } else {
      int mn = min(cnt[find(t[i]-'A')], cnt[find(s[i]-'A')]);
      if(mn == 100) mn = i == 0 ? 9 : 10;
      unite(s[i]-'A', t[i]-'A');
      cnt[find(s[i]-'A')] = mn;
    }
  }
  bool checked[30];
  CLR(checked);
  FOR(i,0,26) {
    if(cnt[find(i)] != 100 && !checked[find(i)]) {
      ans *= cnt[find(i)];
      checked[find(i)] = true;
    }
  }
  cout << ans << endl;
  return 0;
}