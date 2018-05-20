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
// 1つが原点の時 |x1y2 - x2y1| / 2
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int ax,ay,bx,by;
  cin>>ax>>ay>>bx>>by;
  int N; cin >> N;
  int X[N], Y[N];
  FOR(i,0,N) cin >> X[i] >> Y[i];
  int cnt = 0;
  FOR(i,0,N) {
    int x1 = ax - X[i], y1 = ay - Y[i];
    int x2 = bx - X[i], y2 = by - Y[i];
    int x3 = X[(i + 1) % N] - X[i], y3 = Y[(i + 1) % N] - Y[i];
    if((ll)(x1*y3-x3*y1) * (ll)(x2*y3-x3*y2) >= 0) continue;
    x2 = X[i] - ax, y2 = Y[i] - ay;
    x3 = bx - ax, y3 = by - ay;
    x1 = X[(i + 1) % N] - ax, y1 = Y[(i + 1) % N] - ay;
    if((ll)(x1*y3-x3*y1) * (ll)(x2*y3-x3*y2) >= 0) continue;
    cnt++;
  }
  cout << cnt / 2 + 1 << endl;
  return 0;
}