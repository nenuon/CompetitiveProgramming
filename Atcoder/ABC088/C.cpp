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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int c[3][3];
  FOR(i,0,3) FOR(j,0,3) cin >> c[i][j];
  bool ok = true;
  if(c[0][0]-c[1][0] != c[0][1] - c[1][1]) ok = false;
  if(c[0][2]-c[1][2] != c[0][1] - c[1][1]) ok = false;
  if(c[1][0]-c[2][0] != c[1][1] - c[2][1]) ok = false;
  if(c[1][1]-c[2][1] != c[1][2] - c[2][2]) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}