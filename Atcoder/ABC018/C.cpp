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
#include <random>
#include <time.h>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

int main()
{
  int R, C, K;
  cin >> R >> C >> K;
  vector<string> vs(R);
  FOR(i,0,R) cin >> vs[i];
  int ans = 0;
  int up[R][C], down[R][C];
  FOR(i,0,R) FOR(j,0,C) up[i][j] = down[i][j] = 0;
  // 自分含めて上に何個白があるか
  FOR(x,0,C) {
    int cnt = 0;
    FOR(y,0,R) {
      if(vs[y][x] == 'o') cnt++;
      else cnt = 0;
      up[y][x] = cnt;
    }
  }
  // 自分含めて下に何個白があるか
  FOR(x,0,C) {
    int cnt = 0;
    for(int y = R - 1; y >= 0; y--) {
      if(vs[y][x] == 'o') cnt++;
      else cnt = 0;
      down[y][x] = cnt;
    }
  }
  FOR(y, 1, R + 1) {
    FOR(x, 1, C + 1) {
      if(x < K || x > C - K + 1 || y < K || y > R - K + 1) continue;
      bool ok = true;
      FOR(i,0,K) {
        if(up[y - 1][x + i - 1] < K - i || down[y - 1][x + i - 1] < K - i) ok = false;
        if(up[y - 1][x - i - 1] < K - i || down[y - 1][x - i - 1] < K - i) ok = false;
      }
      if(ok) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
