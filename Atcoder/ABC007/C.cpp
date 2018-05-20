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
typedef pair<int, int> P; // 手数、座標
int Z(int y, int x) {
  return 100 * y + x;
}
int main()
{
  int R, C;
  cin >> R >> C;
  int sx, sy, gx, gy;
  cin >> sy >> sx >> gy >> gx;
  sx--;sy--;gx--;gy--;
  vector<string> vs(R);
  FOR(i,0,R) cin >> vs[i];
  int mass[R][C];
  FOR(i,0,R) FOR(j,0,C) mass[i][j] = inf;
  mass[sy][sx] = 0;
  queue<P> Q;
  Q.push(P(0, Z(sy, sx)));
  int vy[4] = {-1, 0, 1, 0};
  int vx[4] = {0, 1, 0, -1};
  while(!Q.empty()) {
    P p = Q.front();Q.pop();
    int nowx = p.second % 100;
    int nowy = p.second / 100;
    FOR(i,0,4) {
      int nexty = nowy + vy[i];
      int nextx = nowx + vx[i];
      if(nexty < 0 || nexty >= R || nextx < 0 || nextx >= C) continue;
      if(vs[nexty][nextx]=='#') continue;
      if(mass[nexty][nextx] <= p.first + 1) continue;
      Q.push(P(p.first+1,Z(nexty, nextx)));
      mass[nexty][nextx] = p.first + 1;
    }
  }
  cout << mass[gy][gx] << endl;
  return 0;
}

