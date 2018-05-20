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
const int inf = 1e9;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // ワーシャルフロイド
  int n,m;// 頂点、辺
  cin >> n >> m;
  int a[100], b[100], c[100], dist[100][100];
  CLR(a);CLR(b);CLR(c);
  FOR(i,0,m){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
    c[i] = 1;
  }
  int ans = 0;
  FOR(t,0,m) {
    FOR(i,0,n){
      FOR(j,0,n){
        if(i==j) dist[i][j] = 0;
        else dist[i][j] = inf;
      }
    }
    // 連結してるとこはcを代入
    FOR(i,0,m){
      if(i == t) continue;
      dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
      dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
    }
    FOR(k,0,n) FOR(i,0,n) FOR(j,0,n) {
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    bool brk = false;
    FOR(i,0,n) {
      FOR(j,0,n) {
        if(dist[i][j] == inf) {
          ans++;
          brk = true;
          break;
        }
      }
      if(brk) break;
    }
  }
  cout << ans << endl;
  return 0;
}