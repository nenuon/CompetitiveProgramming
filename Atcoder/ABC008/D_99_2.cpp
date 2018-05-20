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
int X[30], Y[30];
int memo[100][100][100][100]; // 左下(i,j)、右上(k,l)の長方形での最大値
int N;
int dfs(int x1, int y1, int x2, int y2) {
  if(memo[x1][y1][x2][y2]!=-1) return memo[x1][y1][x2][y2];
  int ret = 0;
  // 範囲内の点選んだ全パターンを調べる
  FOR(i,0,N) {
    if(X[i]<x1||X[i]>x2||Y[i]<y1||Y[i]>y2) continue;
    int tmp = x2 - x1 + y2 - y1 + 1;
    tmp += dfs(x1,y1,X[i]-1,Y[i]-1); // 左下
    tmp += dfs(x1,Y[i]+1,X[i]-1,y2); // 左上
    tmp += dfs(X[i]+1,Y[i]+1,x2,y2); // 右上
    tmp += dfs(X[i]+1,y1,x2,Y[i]-1); // 右下
    ret = max(ret, tmp);
  }
  return memo[x1][y1][x2][y2] = ret;
}
int main()
{
  int W,H;
  cin >> W >> H >> N;
  FOR(i,0,N) cin >> X[i] >> Y[i];
  FOR(i,0,100) FOR(j,0,100) FOR(k,0,100) FOR(l,0,100) memo[i][j][k][l] = -1;
  cout << dfs(1,1,W,H) << endl;
  return 0;
}
