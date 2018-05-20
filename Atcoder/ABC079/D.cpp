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
const int inf = 1e9;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W; cin >> H >> W;
  // ワーシャルフロイド
  int n,m;// 頂点、辺
  int dist[10][10];
  FOR(i,0,10) {
    FOR(j,0,10) {
      int cost; cin >> cost;
      dist[i][j] = cost;
    }
  }

  FOR(k,0,10) FOR(i,0,10) FOR(j,0,10) {
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }
  int ans = 0;
  FOR(h,0,H) {
    FOR(w,0,W) {
      int a; cin >> a;
      if(a == -1 || a == 1) continue;
      ans += dist[a][1];
    }
  }
  cout << ans << endl;
  return 0;
}