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

int main()
{
  // ワーシャルフロイド
  int n, m;// 頂点、辺
  cin >> n >> m;
  int dist[333][333];
  FOR(i,0,n){
    FOR(j,0,n){
      if(i==j) dist[i][j] = 0;
      else dist[i][j] = 1e9;
    }
  }
  // 連結してるとこはcを代入
  FOR(i,0,m){
    int a, b, c;
    cin >> a >> b >> c;
    a--;b--;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
  }
  // ワーシャルフロイド
  FOR(k,0,n) FOR(i,0,n) FOR(j,0,n) {
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }

  int ans = 1e9;
  FOR(i,0,n) {
    // iに引っ越したきの最大値
    int t = 0;
    FOR(j,0,n) {
      if(i == j) continue;
      t = max(t, dist[i][j]);
    }
    ans = min(ans, t);
  }
  cout << ans << endl;
  return 0;
}
