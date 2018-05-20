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
typedef pair<ll, P> PP;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // ワーシャルフロイド
  int n; cin >> n;
  ll dist[n][n];
  vector<PP> v;
  FOR(i,0,n){
    FOR(j,0,n){
      if(i==j) dist[i][j] = 0;
      else dist[i][j] = 1e15;
    }
  }
  FOR(i,0,n) {
    FOR(j,0,n) {
      int in; cin >> in;
      if(j > i) {
        v.push_back(PP(in, P(i, j)));
      }
    }
  }
  sort(v.begin(), v.end());
  ll ans = 0;
  FOR(i,0,v.size()) {
    int x = v[i].second.first;
    int y = v[i].second.second;
    ll cost = v[i].first;
    FOR(k,0,n) dist[x][y] = dist[y][x] = min(dist[x][y], dist[x][k] + dist[k][y]);
    if(dist[x][y] > cost) {
      ans += cost;
      dist[x][y] = dist[y][x] = cost;
    } else if(dist[x][y] < cost) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}