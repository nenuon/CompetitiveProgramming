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
#include <deque>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int N, K; 
int w[1000], p[1000];
// 濃度をx以上にできるか
bool calc(double x) {
  vector<double> v(N);
  FOR(i,0,N) v[i] = w[i] * double(p[i] - x);
  sort(v.rbegin(), v.rend());
  ll sum = 0;
  FOR(i,0,K) sum += v[i];
  return sum >= 0;
}
int main()
{
  cin >> N >> K;
  FOR(i,0,N) cin >> w[i] >> p[i];
  double l = 0.0, r = 100.0;
  FOR(i,0,100) {
    double med = (l + r) * 0.5;
    if(calc(med)) l = med;
    else r = med;
  }
  printf("%.10lf\n", l);
  return 0;
}