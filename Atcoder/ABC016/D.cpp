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
int x_1, y_1, x_2, y_2;
ll area(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}
bool above2(int ay, int ax, int by, int bx) {
  if(area(ax, ay, x_1, y_1, x_2, y_2) * area(bx, by, x_1, y_1, x_2, y_2) >= 0) {
    return false;
  }
  if(area(x_1, y_1, ax, ay, bx, by) * area(x_2, y_2, ax, ay, bx, by) >= 0) {
    return false;
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> x_1 >> y_1 >> x_2 >> y_2;
  int N; cin >> N;
  int X[N], Y[N]; FOR(i,0,N) cin >> X[i] >> Y[i];
  int cnt = 0;
  FOR(i,0,N) {
    if(above2(Y[i % N], X[i % N], Y[(i + 1) % N], X[(i + 1) % N])) {
      cnt++;
    }
  }
  cout << cnt / 2 + 1 << endl;
  return 0;
}