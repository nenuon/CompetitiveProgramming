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
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int T, V;
  cin >> T >> V;
  int n;
  cin >> n;
  int x[n], y[n];
  FOR(i,0,n) cin >> x[i] >> y[i];
  FOR(i,0,n) {
    if(sqrt(pow(x1-x[i],2)+pow(y1-y[i],2))+sqrt(pow(x2-x[i],2)+pow(y2-y[i],2))<=T*V) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
