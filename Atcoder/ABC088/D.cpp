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
typedef pair<int, int> P;
int vy[4] = {-1, 0, 1, 0};
int vx[4] = {0, 1, 0, -1};
int H, W;
vector<string> vs;
int d[60][60];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W;
  int ans = 0;
  FOR(i,0,H) {
    string s; cin >> s;
    FOR(j,0,W) if(s[j] == '.') ans++;
    vs.push_back(s);
  }
  FOR(i,0,60) FOR(j,0,60) d[i][j] = 1e9;
  d[0][0] = 1;
  queue<P> Q;
  Q.push(P(0, 0));
  while(!Q.empty()) {
    P p = Q.front(); Q.pop();
    int y = p.first;
    int x = p.second;
    FOR(i,0,4) {
      int ny = y + vy[i];
      int nx = x + vx[i];
      if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
      if(d[ny][nx] <= d[y][x] + 1) continue;
      if(vs[ny][nx] == '#') continue;
      Q.push(P(ny, nx));
      d[ny][nx] = d[y][x] + 1;
    }
  }
  if(d[H-1][W-1] == 1e9) cout << -1 << endl;
  else cout << ans - d[H-1][W-1] << endl;
  return 0;
}