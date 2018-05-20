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
const int MOD = 1000000007;
int fix[26];
int A[25];
int dp[1<<25];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> v;
  FOR(i,0,26) fix[i] = -1;
  FOR(i,0,25) {
    cin >> A[i];
    if(A[i] == 0) v.push_back(i);
    else fix[A[i]] = i;
  }
  dp[0] = 1;
  FOR(S,0,(1<<25)-1) {
    if(dp[S]) {
      int nx = __builtin_popcount(S) + 1; // 次nxおく
      if(fix[nx] >= 0) {
        int r = fix[nx];
        int y = r / 5, x = r % 5;
        if(((S >> r) & 1) == 0) {
          // 置けないところは隣のどっちか片方に数字がある時
          if(x > 0 && x < 4 && ((S >> (r - 1)) ^ (S >> (r + 1))) & 1) continue;
          if(y > 0 && y < 4 && ((S >> (r - 5)) ^ (S >> (r + 5))) & 1) continue;
          (dp[S | (1 << r)] += dp[S]) %= MOD;
        }
      } else {
        for(int r : v) {
          if(((S >> r) & 1) == 0) {
            int y = r / 5, x = r % 5;
            // 置けないところは隣のどっちか片方に数字がある時
            if(x > 0 && x < 4 && ((S >> (r - 1)) ^ (S >> (r + 1))) & 1) continue;
            if(y > 0 && y < 4 && ((S >> (r - 5)) ^ (S >> (r + 5))) & 1) continue;
            (dp[S | (1 << r)] += dp[S]) %= MOD;
          }
        }
      }
    }
  }
  cout << dp[(1<<25)-1] << endl;
  return 0;
}