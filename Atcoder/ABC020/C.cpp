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
typedef pair<ll, int> P;
// 二分探索

int H, W, T;
int s, g;
int vy[4] = {-1, 0, 1, 0};
int vx[4] = {0, 1, 0, -1};
int Z(int y, int x) {
  return 20 * y + x;
}
bool calc(vector<string> vs, ll x) {
  ll d[300];
  FOR(i,0,300) d[i] = 1000000000000000;
  d[s] = 0;
  priority_queue<P, vector<P>, greater<P> > Q;
  Q.push(P(0, s)); // 最短距離、場所
  while(!Q.empty()) {
    P p = Q.top(); Q.pop();
    if(d[p.second] < p.first) continue;
    FOR(i,0,4) {
      int nx = p.second % 20 + vx[i];
      int ny = p.second / 20 + vy[i];
      ll nd;
      if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
      if(vs[ny][nx] == '#') nd = p.first + x;
      else nd = p.first + 1;
      if(d[Z(ny, nx)] > nd) {
        d[Z(ny, nx)] = nd;
        Q.push(P(nd, Z(ny, nx)));
      }
    }
  }
  return T >= d[g];
}

int main()
{
  cin >> H >> W >> T;
  vector<string> vs(H);
  FOR(i,0,H) cin >> vs[i];
  FOR(y,0,H) FOR(x,0,W) {
    if(vs[y][x] == 'S') s = Z(y, x);
    if(vs[y][x] == 'G') g = Z(y, x);
  }
  ll l = 0, r = 1000000000;
  while(r - l > 1) {
    int med = (r + l) / 2;
    if(calc(vs, med)) l = med;
    else r = med;
  }
  cout << l << endl;
  return 0;
}
