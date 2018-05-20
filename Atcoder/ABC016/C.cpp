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
const int inf = 1e9;
int main()
{
  int n, m;// 頂点、辺
  cin >> n >> m;
  int a[1000], b[1000], c[1000], dist[100][100];
  FOR(i,0,m){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
  }
  FOR(i,0,n){
    FOR(j,0,n){
      if(i==j) dist[i][j] = 0;
      else dist[i][j] = inf;
    }
  }
  // 連結してるとこはcを代入
  FOR(i,0,m){
    dist[a[i]][b[i]] = min(dist[a[i]][b[i]], 1);
    dist[b[i]][a[i]] = min(dist[b[i]][a[i]], 1);
  }
  // ワーシャルフロイド
  FOR(k,0,n) FOR(i,0,n) FOR(j,0,n) {
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }
  // iの人について
  FOR(i,0,n) {
    int cnt = 0;
    FOR(j,0,n) {
      if(dist[i][j] == 2) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
