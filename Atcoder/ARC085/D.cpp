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
int N, Z, W;
int a[2222];
int dp[2222][2222];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Z >> W;
  FOR(i,0,N) cin >> a[i];
  FOR(i,0,2222) FOR(j,0,2222) dp[i][j] = -1;
  // Aさんがibさんがjを取った状態で今後得られるscore
  dp[N-1][N] = abs(a[N-1] - W);
  for(int i = N - 2; i >= 0; i--) {
    for(int j = N - 1; j > i; j--) {
      dp[i][j] = 
    }
    // 
  }
}