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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

int main()
{
  int N, D, X, Y;
  cin >> N >> D >> X >> Y;
  X = abs(X);
  Y = abs(Y);
  // 一回でD進むのだからDで割り切れなかったら無理
  if(X % D || Y % D) {
    cout << 0 << endl;
    return 0;
  }
  X /= D;
  Y /= D;
  // 全パターン中選ばれる確率
  // パスカルの三角形で組み合わせの数求めるやつと同じ
  double p[1010][1010];
  FOR(i,0,1010) FOR(j,0,1010) p[i][j] = 0;
  p[0][0] = 1;
  FOR(i,0,1005) {
    FOR(j,0,1005) {
      p[i+1][j] += p[i][j] * 0.5;
      p[i+1][j+1] += p[i][j] * 0.5;
    }
  }
  double ans = 0;
  // x方向にk回いく時
  FOR(k,0,N+1) {
    int vx = k;
    int vy = N - vx;
    if(Y>vy||X>vx) continue;
    if((vx-X)%2==1||(vy-Y)%2==1) continue;
    double tmp = 1;
    tmp *= p[N][k];
    tmp *= p[vx][(vx-X)/2];
    tmp *= p[vy][(vy-Y)/2];
    ans += tmp;
  }
  printf("%.14f\n", ans);
  return 0;
}
