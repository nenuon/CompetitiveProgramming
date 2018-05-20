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
// 出力の白い部分の周りはもともと白なので一旦戻してから、
// 収縮を行い一致すればOKです!
int H, W;
vector<string> af, bef, ans;
int vy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int vx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void beWhite(int y, int x) {
  FOR(i,0,8) {
    if(y+vy[i]<0 || y+vy[i]>=H || x+vx[i]<0 || x+vx[i]>=W) continue;
    af[y+vy[i]][x+vx[i]] = '.';
  }
}
void beBlack(int y, int x) {
  bool be = false;
  FOR(i,0,8) {
    if(y+vy[i]<0 || y+vy[i]>=H || x+vx[i]<0 || x+vx[i]>=W) continue;
    if(ans[y+vy[i]][x+vx[i]] == '#') be = true;
  }
  if(be) af[y][x] = '#';
}
int main()
{
  cin >> H >> W;
  FOR(i,0,H) {
    string in;
    cin >> in;
    af.push_back(in);
    bef.push_back(in);
  }
  FOR(y,0,H) {
    FOR(x,0,W) {
      if(bef[y][x]=='.') beWhite(y,x);
    }
  }
  ans = af;
  FOR(y,0,H) FOR(x,0,W) beBlack(y,x);
  bool pos = true;
  FOR(y,0,H) {
    FOR(x,0,W) {
      if(af[y][x]!=bef[y][x]) pos = false;
    }
  }
  if(pos) {
    cout << "possible" << endl;
    FOR(y,0,H) {
      cout << ans[y] << endl;
    }
  } else {
    cout << "impossible" << endl;
  }
  return 0;
}
