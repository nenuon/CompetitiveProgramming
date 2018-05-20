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
int para[100005]; //oya
int rnka[100005]; //ki no hu ka sa
map<P, int> D; // 距離
//木の根を求める
int find(int x){
    if(para[x] == x) return x;
    else return para[x] = find(para[x]);
}
//xとyの属する集合を併合
void unite(int x, int y){
    x = find(x);y = find(y);
    if(x == y) return;
    para[x] = y;
    /*
    if(rnka[x] < rnka[y]) para[x] = y;
    else {
      para[y] = x;
      if(rnka[x] == rnka[y]) rnka[x]++;
    }
    */
}
bool isSame(int x, int y) {
  return find(x) == find(y);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M; cin >> N >> M;
  bool ok = true;
  FOR(i, 0, 100005) para[i] = i;
  FOR(i, 0, 100005) D[P(i, i)] = 0;
  FOR(i,0,M) {
    int l, r, d;
    cin >> l >> r >> d;
    int p = find(l);
    //if(D.count(P(r, p))) ok = false;
    if(D.count(P(l, r))) {
      if(D[P(l, r)] != d) ok = false;
    } else {
      if(D.count(P(p, r)) == 0) {
        D[P(l, r)] = d;
        D[P(p, r)] = d + D[P(p, l)];
      } else {
        if(D[P(p, l)] + d != D[P(p, r)]) ok = false;
      }
    }
    unite(l, r);
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl; 
}