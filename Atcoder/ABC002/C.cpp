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
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  c -= a;
  d -= b;
  e -= a;
  f -= b;
  printf("%lf\n", abs(c * f - d * e) / 2.0);
  return 0;
}
