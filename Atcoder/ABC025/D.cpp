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
int A[25];
int fix[26]; // すでに指定されている数字の場所
int dp[1<<25];
vector<int> v;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  FOR(i,0,26) fix[i] = -1;
  FOR(i,0,25) {
    cin >> A[i];
    if(A[i] == 0) v.push_back(i);
    else fix[A[i]] = i;
  }
  // 1,2,3...の順に数字を置いていく
  dp[0] = 1;
  FOR(mask,0,(1<<25)-1) {
    if(dp[mask] <= 0) continue;
    int b = __builtin_popcount(mask) + 1; // 次におく数字
    // 場所がすでに指定されている
    if(fix[b] >= 0) {
      int r = fix[b]; // 場所
      int y = r / 5, x = r % 5; // (y, x)に直す
      // まだ置かれていない
      if((mask & (1 << r)) == 0) {
        // 端っこでない && すでに数字が隣(片方)に置かれていたらだめ
        if(y > 0 && y < 4 && ((mask >> (r - 5)) ^ (mask >> (r + 5))) & 1) continue;
        if(x > 0 && x < 4 && ((mask >> (r - 1)) ^ (mask >> (r + 1))) & 1) continue;
        dp[mask ^ (1 << r)] += dp[mask];
        dp[mask ^ (1 << r)] %= MOD;
      }
    } else {
      // toにおく
      for(int r : v) {
        int y = r / 5, x = r % 5;
        // まだ置かれていない
        if((mask & (1 << r)) == 0) {
          // 端っこでない && すでに数字が隣に置かれていたらだめ
          if(y > 0 && y < 4 && ((mask >> (r - 5)) ^ (mask >> (r + 5))) & 1) continue;
          if(x > 0 && x < 4 && ((mask >> (r - 1)) ^ (mask >> (r + 1))) & 1) continue;
          dp[mask ^ (1 << r)] += dp[mask];
          dp[mask ^ (1 << r)] %= MOD;
        }
      }
    }
  }
  cout << dp[(1<<25)-1] << endl;
  return 0;
}