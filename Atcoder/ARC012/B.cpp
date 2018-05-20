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
  int N; cin >> N;
  int va, vb; cin >> va >> vb;
  double L; cin >> L;
  while(N--) {
    double t = L / va;
    L = L + (vb - va) * t;
  }
  printf("%.10lf\n", L);
  return 0;
}
