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
#define CLR(mat) memset(mat, -1, sizeof(mat))
typedef long long ll;
// dp[i][j][b] := i枚目まで見ていて、j枚食べていて、k=「その時点までのMAXを食べているかどうか」
double dp[2020][2020][2];
int N, K;
double solve(int i, int j, int b) {
  if(i == N) return b; // 1 or 0
  double &r = dp[i][j][b];
  if(r != -1) return r;
  // (1-1/i)の確率で最大値は更新されない
  r = solve(i + 1, j, f) * (1.0 * i / (i + 1));
  // 1/iの確率で最大値が更新される, 食べるか食べないかいい方を採用する
  double t = solve(i + 1, j, 0);
  if(j + 1 <= K) t = max(t, solve(i + 1, j + 1, 1));
  r += t / (i + 1);
  return r;
}
int main()
{
  CLR(dp);
  printf("%.10lf\n", solve(0, 0, 0));
  return 0;
}