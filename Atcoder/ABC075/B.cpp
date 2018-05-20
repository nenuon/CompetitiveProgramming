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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W; cin >> H >> W;
  vector<string> vs(H);
  FOR(i,0,H) cin >> vs[i];
  int vy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int vx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
  FOR(h,0,H) {
    FOR(w,0,W) {
      if(vs[h][w] == '.') {
        int cnt = 0;
        FOR(i,0,8) {
          int y = h + vy[i];
          int x = w + vx[i];
          if(y >= 0 && y < H && x >= 0 && x < W && vs[y][x] == '#') cnt++;
        }
        vs[h][w] = char('0' + cnt);
      }
    }
  }
  FOR(i,0,H) cout << vs[i] << endl;
  return 0;
}