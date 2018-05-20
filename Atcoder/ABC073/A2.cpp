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

int main()
{
  int n, m, R; cin >> n >> m >> R;
  vector<int> r(R); FOR(i,0,R) cin >> r[i];
  sort(r.begin(), r.end());
  int a[m], b[m], c[m], dist[n+1][n+1];
  FOR(i,0,m) cin >> a[i] >> b[i] >> c[i];
  FOR(i,0,n+1){
    FOR(j,0,n+1){
      if(i==j) dist[i][j] = 0;
      else dist[i][j] = 1e9;
    }
  }
  // 連結してるとこはcを代入
  FOR(i,0,m){
    dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
    dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
  }
  // ワーシャルフロイド
  FOR(k,1,n+1) FOR(i,1,n+1) FOR(j,1,n+1) {
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }
  int ans = 1e9;
  do {
    int d = 0;
    FOR(i,0,R-1) d += dist[r[i]][r[i+1]];
    ans = min(ans, d);
  } while(next_permutation(r.begin(), r.end()));
  cout << ans << endl;
  return 0;
}
