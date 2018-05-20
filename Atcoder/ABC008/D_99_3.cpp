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
#define CLR(mat) memset(mat, -1, sizeof(mat))
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, P> PPAP;
int W, H, N;
int X[30], Y[30];
map<PPAP, ll> MAP;
ll dfs(int ly, int lx, int ry, int rx) {
  if(MAP.count(PPAP(P(ly,lx),P(ry,rx)))) return MAP[PPAP(P(ly,lx),P(ry,rx))];
  ll ret = 0;
  FOR(i,0,30) {
    if(X[i]<lx||X[i]>rx||Y[i]>ly||Y[i]<ry) continue;
    ll mx = (ll)ly - ry + rx - lx + 1;
    mx += dfs(ly,lx,Y[i]+1,X[i]-1);
    mx += dfs(ly,X[i]+1,Y[i]+1,rx);
    mx += dfs(Y[i]-1,X[i]+1,ry,rx);
    mx += dfs(Y[i]-1,lx,ry,X[i]-1);
    ret = max(ret, mx);
  }
  MAP[PPAP(P(ly,lx),P(ry,rx))] = ret;
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> W >> H >> N;
  FOR(i,0,N) cin >> X[i] >> Y[i];
  cout << dfs(H, 1, 1, W) << endl;
  return 0;
}