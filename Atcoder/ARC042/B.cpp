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
  int x0, y0; cin >> x0 >> y0;
  int N; cin >> N;
  double x[N], y[N]; FOR(i,0,N) cin >> x[i] >> y[i];
  double ans = 1e9;
  FOR(i,0,N) {
    int j = i + 1;
    if(j == N) j = 0;
    double d;
    if(x[j] == x[i]) {
      d = abs(x0 - x[i]);
    } else if(y[j] == y[i]){
      d = abs(y0 - y[i]);
    } else {
      double m = (y[j] - y[i]) / (x[j] - x[i]);
      double X = (m * m * x[i] + x0 - m * (y[i] - y0)) / (1 + m * m);
      double Y = m * (X - x[i]) + y[i];
      X = min(max(x[i], x[j]), max(X, min(x[i], x[j])));
      Y = min(max(y[i], y[j]), max(Y, min(y[i], y[j])));
      d = sqrt(pow(X - x0, 2) + pow(Y - y0, 2));
    }
    ans = min(ans, d);
  }
  printf("%.10lf\n",ans);
  return 0;
}
