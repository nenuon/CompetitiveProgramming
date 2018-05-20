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
#define PI acos(-1)
typedef long long ll;
int main()
{
  double A, B, C; cin >> A >> B >> C;
  double l = - 1 / (2 * C);
  double r = 1 / (2 * C);
  while(1) {
    if(sin(C*l*PI)*B<=100-A*l && sin(C*r*PI)*B>=100-A*r) break;
    l += 1 / C;
    r += 1 / C;
  }
  FOR(i,0,100) {
    double med = (r + l) * 0.5;
    if((100 - A * med) / B >= sin(C * med * PI)) l = med;
    else r = med;
  }
  //cout << (100 - A * l) / B << " " << sin(C * l * PI) << endl;
  printf("%.10lf\n", l);
  return 0; 
}