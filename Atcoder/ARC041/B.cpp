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
// 周りから
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W; cin >> H >> W;
  vector<string> vs(H); FOR(i,0,H) cin >> vs[i];
  int b[H][W]; FOR(i,0,H) FOR(j,0,W) b[i][j] = vs[i][j] - '0';
  int ans[H][W]; CLR(ans);
  int vy[4] = {-1,0,1,0};
  int vx[4] = {0,1,0,-1};
  FOR(k,1,max(H,W)) {
    FOR(y,1,H-1) {
      FOR(x,1,W-1) {
        if(y == k || y == H - k - 1 || x == k || x == W - k - 1) {
          int mn = 10;
          FOR(i,0,4) mn = min(mn, b[y+vy[i]][x+vx[i]]);
          ans[y][x] += mn;
          FOR(i,0,4) b[y+vy[i]][x+vx[i]] -= mn;
        }
      }
    }
  }
  FOR(i,0,H) {
    FOR(j,0,W) {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
