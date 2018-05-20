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
// 平均最大化
int N, K;
double w[1000], p[1000];
bool calc(double pp) {
  vector<double> v;
  FOR(i,0,N) {
    v.push_back((p[i] - pp) * w[i]);
  }
  sort(v.rbegin(), v.rend());
  double m = 0;
  FOR(i,0,K) m += v[i];
  return m >= 0; 
}
int main()
{
  cin >> N >> K;
  FOR(i,0,N) cin >> w[i] >> p[i];
  double l = -1, r = 1000;
  FOR(i,0,100) {
    double m = (l + r) * 0.5;
    if(calc(m)) l = m;
    else r = m;
  }
  printf("%.10lf\n",l);
  return 0;
}