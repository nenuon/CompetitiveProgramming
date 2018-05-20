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
// 根のペアが同じならどちらでも連結している
// union - find tree !!!!!!!!!!!!!!!!!!!!!!!!!
vector<vector<int> > par; //oya
vector<vector<int> > rnk; //ki no hu ka sa
// n要素で初期化
void init(int n){
    par.resize(2, vector<int>(n));
    rnk.resize(2, vector<int>(n));
    FOR(i,0,n)FOR(j,0,2){par[j][i] = i;rnk[j][i] = 0;}
}
//木の根を求める
int find(int x, int k){
    if(par[k][x] == x) return x;
    else return par[k][x] = find(par[k][x], k);
}
//xとyの属する集合を併合
void unite(int x, int y, int k){
    x = find(x, k);y = find(y, k);
    if(x == y) return;
    if(rnk[k][x] < rnk[k][y])par[k][x] = y;
    else{par[k][y] = x;if(rnk[k][x] == rnk[k][y]) rnk[k][x]++;}
    return;
}
bool isSame(int x, int y, int k){return find(x, k) == find(y, k);}
int main()
{
  int N, K, L;
  cin >> N >> K >> L;
  map<P, int> MAP;
  init(N+1);
  FOR(i,0,K) {
    int a, b; cin >> a >> b;
    unite(a, b, 0);
  }
  FOR(i,0,L) {
    int a, b; cin >> a >> b;
    unite(a, b, 1);
  }
  FOR(i,1,N+1) MAP[P(find(i,0), find(i,1))]++;
  FOR(i,1,N+1) {
    printf("%d%c",MAP[P(find(i,0), find(i,1))],i==N?'\n':' ');
  }
  return 0;
}
