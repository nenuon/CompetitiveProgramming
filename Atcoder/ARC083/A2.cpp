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
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
typedef pair<int, int> P;
bool dp[3333][3333];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  CLR(dp);
  dp[0][0] = true;
  FOR(i,0,3003) {
    FOR(j,0,3003) {
      if(i >= 100 * A) dp[i][j] |= dp[i - 100 * A][j];
      if(i >= 100 * B) dp[i][j] |= dp[i - 100 * B][j];
      if(j >= C) dp[i][j] |= dp[i][j - C];
      if(j >= D) dp[i][j] |= dp[i][j - D];
    }
  }
  P mx = P(0, 100 * A);
  FOR(i, 1, 3001)
  {
    FOR(j,0,3001) {
      if(!dp[i][j]) {
        continue;
      }
      if(i + j <= F) {
        if(i * E >= 100 * j) {
          if(100 * j * mx.second > mx.first * (i + j)) {
            mx = P(100 * j, i + j);
          }
        }
      }
    }
  }
  cout << mx.second << " " << mx.first / 100 << endl;
  return 0;
}