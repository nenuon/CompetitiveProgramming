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
bool dpR[4040][16010], dpU[4040][16010];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s; cin >> s;
  int x, y; cin >> x >> y;
  int sx = 0, sy = 0;
  vector<int> r, u;
  bool ud = false;
  int i = 0;
  bool start = true;
  while(i < s.length()) {
    if(s[i] == 'T') {
      ud = ud ^ 1;
      i++;
      start = false;
    }
    int cntF = 0;
    while(s[i] == 'F') {
      i++;
      cntF++;
    }
    if(ud) u.push_back(cntF);
    else {
      if(start) {
        sx = cntF;
        start = false;
      }
      else r.push_back(cntF);
    }
  }
 
  CLR(dpR);
  CLR(dpU);
  int cen = 8000;
  dpR[0][cen+sx] = true;
  dpU[0][cen] = true;
  FOR(i,0,r.size()) {
    FOR(j,0,16001) {
      if(dpR[i][j]) {
        dpR[i+1][j+r[i]] = true;
        dpR[i+1][j-r[i]] = true;
      }
    }
  }
  FOR(i,0,u.size()) {
    FOR(j,0,16001) {
      if(dpU[i][j]) {
        dpU[i+1][j+u[i]] = true;
        dpU[i+1][j-u[i]] = true;
      }
    }
  }
  bool ans = dpR[r.size()][x+cen] && dpU[u.size()][y+cen];
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}