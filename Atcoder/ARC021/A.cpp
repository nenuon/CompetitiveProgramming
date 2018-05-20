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
  int A[4][4];
  FOR(i,0,4) FOR(j,0,4) cin >> A[i][j];
  int vy[4] = {1, 0, -1, 0};
  int vx[4] = {0, 1, 0, -1};
  FOR(y,0,4) {
    FOR(x,0,4) {
      bool ok = false;
      FOR(i,0,4) {
        int nx = x + vx[i];
        int ny = y + vy[i];
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        if(A[y][x] == A[ny][nx]) ok = true;
      }
      if(ok) {
        puts("CONTINUE");
        return 0;
      }
    }
  }
  puts("GAMEOVER");
  return 0;
}
