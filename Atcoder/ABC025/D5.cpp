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
#define FOR(I, A, B) for (int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
const int MOD = 1000000007;
ll dp[1 << 25];
int f[26]; // 数字iを置かなければいけない場所
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  FOR(i, 0, 26)
  f[i] = -1;
  FOR(i, 0, 25)
  {
    int in;
    cin >> in;
    if (in != 0)
    {
      f[in] = i;
    }
  }
  dp[0] = 1;
  FOR(i, 0, (1 << 25) - 1)
  {
    if (dp[i])
    {
      // 次に置く数字
      int nxt = __builtin_popcount(i) + 1;
      // 置く場所が決まってる
      if (f[nxt] != -1)
      {
        int r = f[nxt];
        if ((i & (1 << r)) == 0)
        {
          int x = r % 5;
          int y = r / 5;
          if(x > 0 && x < 4 && (((i >> (r - 1)) & 1) ^ ((i >> (r + 1)) & 1)) & 1) continue;
          if(y > 0 && y < 4 && (((i >> (r - 5)) & 1) ^ ((i >> (r + 5)) & 1)) & 1) continue;
          dp[i | (1 << r)] += dp[i];
          dp[i | (1 << r)] %= MOD;
        }
      }
      else
      {
        // jに置く
        FOR(j, 0, 25)
        {
          int r = j;
          if ((i & (1 << r)) == 0)
          {
            int x = r % 5;
            int y = r / 5;
            if(x > 0 && x < 4 && (((i >> (r - 1)) & 1) ^ ((i >> (r + 1)) & 1)) & 1) continue;
            if(y > 0 && y < 4 && (((i >> (r - 5)) & 1) ^ ((i >> (r + 5)) & 1)) & 1) continue;
            dp[i | (1 << r)] += dp[i];
            dp[i | (1 << r)] %= MOD;
          }
        }
      }
    }
  }
  cout << dp[(1 << 25) - 1] << endl;
  return 0;
}