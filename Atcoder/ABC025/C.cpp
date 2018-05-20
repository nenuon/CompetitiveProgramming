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
typedef pair<int, int> pint;
int b[2][3], c[3][2];
pint dfs(vector<string> &vs) {
  int n = 0;
  FOR(y,0,3) FOR(x,0,3) if(vs[y][x] != '.') n++;
  pint ret = pint(0, 0);
  if(n == 9) {
    FOR(y,0,2) FOR(x,0,3) {
      if(vs[y][x] == vs[y+1][x]) ret.first += b[y][x];
      else ret.second += b[y][x];
    }
    // c
    FOR(y,0,3) FOR(x,0,2) {
      if(vs[y][x] == vs[y][x+1]) ret.first += c[y][x];
      else ret.second += c[y][x];
    }
    return ret;
  }
  // nokoriが奇数->直大さんの得点が大きいやつにする
  FOR(y,0,3) FOR(x,0,3) {
    if(vs[y][x] != '.') continue;
    vs[y][x] = "ox"[n % 2];
    pint nx = dfs(vs);
    vs[y][x] = '.';
    if(n % 2) swap(nx.first, nx.second);
    ret = max(ret, nx);
  }
  if(n % 2) swap(ret.first, ret.second);
  return ret;
}

int main()
{
  FOR(i,0,2) FOR(j,0,3) cin >> b[i][j];
  FOR(i,0,3) FOR(j,0,2) cin >> c[i][j];
  vector<string> s(3, "...");
  pint ans = dfs(s);
  cout << ans.first << endl;
  cout << ans.second << endl;
  return 0;
}
