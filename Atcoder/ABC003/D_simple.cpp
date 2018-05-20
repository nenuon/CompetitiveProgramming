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
int range_sum(int n) {
  return n * (n + 1) / 2;
}
int score(int L, int R) {
  if(R <= 0) return range_sum(-L) - range_sum(-R-1);
  if(L >= 0) return range_sum(R) - range_sum(L-1);
  return range_sum(R) + range_sum(-L);
}
int calc_score(int gL, int r, int g, int b) {
  int gR = gL + g - 1;
  int rR = min(-100 + (r-1)/2, gL - 1);
  int rL = rR - r + 1;
  int bL = max(100 + (b-1)/2, gR + 1);
  int bR = bL + b - 1;
  return score(gL, gR) + score(rL+100,rR+100) + score(bL-100,bR-100);
}
int solve(int r, int g, int b) {
  int ans = 1e9;
  FOR(gL, -1000, 1000) {
    ans = min(ans, calc_score(gL, r, g, b));
  }
  return ans;
}
int main()
{
  int r,g,b;
  cin>>r>>g>>b;
  cout << solve(r,g,b) << endl;
  return 0;
}
