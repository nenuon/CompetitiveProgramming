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
  ll N, K;
  cin >> N >> K;
  ll wa = (N - K) * (K - 1) * 6 + (N - 1) * 3 + 1;
  ll b = N * N * N;
  double ans = (double)wa / b;
  printf("%.011lf\n", ans);
  return 0;
}
