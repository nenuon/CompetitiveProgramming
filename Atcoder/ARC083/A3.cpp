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
int n,m;// 頂点、辺
ll dist[333][333];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  m = n * n;
  FOR(i, 1, n + 1){
    FOR(j, 1, n + 1) {
      cin >> dist[i][j];
    }
  }
  ll ans = 0;
  FOR(i, 1, n + 1){
    FOR(j, i + 1, n + 1) {
      bool use = true;
      FOR(k, 1, n + 1) {
        if(i == j || k == i || k == j) continue;
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          cout << -1 << endl;
          return 0;
        }
        if(dist[i][j] == dist[i][k] + dist[k][j]){
          use = false;
        }
      }
      if(use) ans += dist[i][j];
    }
  }
  cout << ans << endl;
  return 0;
}