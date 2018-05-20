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
const int MOD = 1000000007;
ll IE(ll b) {
  ll ret = 1;
  ll M = MOD - 2;
  for (; M; b = (b * b) % MOD, M >>= 1) {
    if(M & 1) ret = (ret * b) % MOD;
  }
  return ret % MOD;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll A, B, C;
  cin >> A >> B >> C;
  ll c = B * C % MOD - A * B % MOD + MOD;
  ll r = B * C % MOD - A * C % MOD + MOD;
  c = c * IE(A * C % MOD - B * C % MOD + A * B % MOD + MOD) % MOD;
  r = r * IE(A * B % MOD - B * C % MOD + A * C % MOD + MOD) % MOD;
  cout << r << " " << c << endl;
  return 0;
}