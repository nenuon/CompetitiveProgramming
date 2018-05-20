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

double dp[1010][1010];
void makeCP() {
  CLR(dp);
  dp[0][0] = 1;
  FOR(i,1,1010) {
    FOR(j,0,1010) {
      dp[i][j] += dp[i-1][j] / 2.0;
      dp[i][j+1] += dp[i-1][j] / 2.0;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  makeCP();
  int N; cin >> N;
  ll D, X, Y; cin >> D >> X >> Y;
  if(X%D!=0 || Y%D!=0) {
    cout << 0 << '\n';
    return 0;
  }
  X /= D; Y /= D;
  X = abs(X); Y = abs(Y);
  double ans = 0;
  // 横にA回移動するとき
  FOR(A,0,N+1) {
    if((A-X)%2!=0 || (N-A-Y)%2!=0) continue;
    double p = dp[N][A]; // N回中横にA回
    p *= dp[A][(A-X)/2];
    p *= dp[N-A][(N-A-Y)/2];
    ans += p;
  }
  printf("%.010lf\n", ans);
  return 0;
}
