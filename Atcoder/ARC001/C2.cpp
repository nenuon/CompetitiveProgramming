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
const int H = 8;
const int W = 8;
vector<string> vs(H);
bool okeru(int y, int x) {
  FOR(vy,-1,2) {
    FOR(vx,-1,2) {
      if(vy == 0 && vx == 0) continue;
      int d = 1;
      int Y = y + d * vy;
      int X = x + d * vx;
      while(Y >= 0 && Y < H && X >= 0 && X < W) {
        if(vs[Y][X] == 'Q') return false;
        d++;
        Y = y + d * vy;
        X = x + d * vx;
      }
    }
  }
  return true;
}

void dfs(int y, int x, int n) {
  if(n == 8) {
    FOR(i,0,H) cout << vs[i] << endl;
    exit(0);
  }
  if(y >= H || x >= W) return;
  if(vs[y][x] == 'Q' && okeru(y, x)) {
    dfs(y + 1, 0, n + 1);
  } else if(okeru(y, x)) {
    vs[y][x] = 'Q';
    dfs(y + 1, 0, n + 1);
    vs[y][x] = '.';
  }
  dfs(y, x + 1, n);
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  FOR(i,0,H) cin >> vs[i];
  dfs(0, 0, 0);
  puts("No Answer");
  return 0;
}
