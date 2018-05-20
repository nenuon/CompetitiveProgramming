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
typedef pair<int, int> P; // 座標、残りの壊せる回数
int Z(int y, int x) {
  return 500 * y + x;
}
int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> vs(H);
  FOR(i,0,H) cin >> vs[i];
  int s, g;
  FOR(y,0,H) {
    FOR(x,0,W) {
      if(vs[y][x] == 's') s = Z(y, x);
      if(vs[y][x] == 'g') g = Z(y, x);
    }
  }
  int nokori[H][W];
  FOR(y,0,H) FOR(x,0,W) nokori[y][x] = -1;
  int vx[4] = {0, 1, 0, -1};
  int vy[4] = {-1, 0, 1, 0};
  queue<P> Q;
  Q.push(P(s, 2));
  while(!Q.empty()) {
    P p = Q.front();Q.pop();
    int y = p.first / 500;
    int x = p.first % 500;
    FOR(i,0,4) {
      int ny = y + vy[i];
      int nx = x + vx[i];
      if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
      if(vs[ny][nx] == '#') {
        if(p.second > 0) {
          if(nokori[ny][nx] >= p.second - 1) continue;
          nokori[ny][nx] = p.second - 1;
          Q.push(P(Z(ny, nx), p.second - 1));
        }
      } else {
        if(nokori[ny][nx] >= p.second) continue;
        nokori[ny][nx] = p.second;
        Q.push(P(Z(ny, nx), p.second));
      }
    }
  }
  puts(nokori[g/500][g%500]==-1?"NO":"YES");
  return 0;
}
