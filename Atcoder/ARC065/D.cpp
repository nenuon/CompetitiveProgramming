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
typedef pair<int, int> P;
// 二つのunion-find
int par[200005][2];
int rnk[200005][2];
// n要素で初期化
void Init(int n){
  //par.resize(n);rnk.resize(n);
  FOR(i,0,n) FOR(j,0,2){par[i][j]=i;rnk[i][j]=0;}
}
//木の根を求める
int Find(int i, int x){
  if(par[x][i] == x) return x;
  else return par[x][i] = Find(i, par[x][i]);
}
//xとyの属する集合を併合
void Merge(int i, int x, int y){
  x = Find(i,x);y = Find(i,y);
  if(x == y) return;
  if(rnk[x][i] < rnk[y][i]) par[x][i] = y;
  else{par[y][i] = x;if(rnk[x][i] == rnk[y][i]) rnk[x][i]++;}
  return;
}

int main()
{
  int N, K, L;
  cin >> N >> K >> L;
  Init(N+1);
  // 道路のグループ
  FOR(i,0,K) {
    int a, b;
    cin >> a >> b;
    Merge(0, a, b);
  }
  // 鉄道のグループ
  FOR(i,0,L) {
    int a, b;
    cin >> a >> b;
    Merge(1, a, b);
  }
  // 属するグループの親のpairが同じなら両方繋がっている
  map<P, int> MAP;
  FOR(i,1,N+1) MAP[P(Find(0,i),Find(1,i))]++;
  FOR(i,1,N+1) {
    printf("%d%c", MAP[P(Find(0,i),Find(1,i))], i == N ? '\n' : ' ');
  }
  return 0;
}
