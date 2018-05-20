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
typedef pair<double, int> P;
// 答え見た
// 平均の最大化は先に答え決めてしまって二分探索が使える
int N, K;
ll w[1010], p[1010];
bool check(double x) {
  vector<P> v(N);
  FOR(i, 0, N) {
    v[i] = P(w[i] * ((p[i] - x) / 100), i);
  }
  sort(v.rbegin(), v.rend());
  // x%以上になるかどうか
  ll sio = 0, W = 0;
  FOR(i, 0, K)
  {
    int j = v[i].second;
    sio += w[j] * p[j];
    W += w[j];
  }
  return (double)sio / W >= x;
}
int main()
{
  cin >> N >> K;
  FOR(i, 0, N) {
    cin >> w[i] >> p[i];
  }
  double l = 0, r = 100;
  FOR(i,0,100) {
    double med = (r + l) / 2;
    if(check(med)) {
      l = med;
    } else {
      r = med;
    }
  }
  printf("%.10lf\n", l);
  return 0;
}
