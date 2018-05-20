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
  int N; cin >> N;
  int x[N], y[N], c[N];
  FOR(i,0,N) cin >> x[i] >> y[i] >> c[i];
  double ans = 0;
  FOR(i,0,N-1) {
    FOR(j,i+1,N) {
      double dx = fabs(x[i]-x[j]);
      double dy = fabs(y[i]-y[j]);
      ans = max(ans, double(c[i]*c[j])*dx/(c[i]+c[j]));
      ans = max(ans, double(c[i]*c[j])*dy/(c[i]+c[j]));
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}
