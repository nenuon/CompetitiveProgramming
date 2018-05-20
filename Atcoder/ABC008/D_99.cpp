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
int memo[100][100][100][100];
int N;
int solve(int x1, int y1, int x2, int y2) {
  if(memo[x1][y1][x2][y2]!=-1) return memo[x1][y1][x2][y2];
  int ret = 0;
  FOR(i,0,N) {
    if(x1<X[i]||x2<X[i]||y1>Y[i]||y2<Y[i]) continue; // クレーンが範囲の外側
    int sum = x2 - x1 + y2 - y1 + 1;
    sum += solve(x1,y1,X[i]-1,Y[i]-1); // 左下
    sum += solve(x1,Y[i]+1,X[i]-1,y2); // 左上
    sum += solve(X[i]+1,Y[i]+1,x2,y2); // 右上
    sum += solve(X[i]+1,y1,x2,Y[i]-1); // 右下
    ret = min(ret, sum);
  }
  return memo[x1][y1][x2][y2] = ret;
}
int main()
{

}
