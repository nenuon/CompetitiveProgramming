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
#include <complex>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
// 平行移動(複素平面上 -A => / B * |AB|)して三角形ABCの面積求める
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  ll x[N], y[N]; FOR(i,0,N) cin >> x[i] >> y[i];
  int ans = 0;
  FOR(i,0,N-2) {
    FOR(j,i+1,N-1) {
      FOR(k,j+1,N) {
        ll xb = x[j] - x[i];
        ll yb = y[j] - y[i];
        ll xc = x[k] - x[i];
        ll yc = y[k] - y[i];
        ll m = abs(xb * yc - xc * yb);
        if(m != 0 && m % 2 == 0) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
