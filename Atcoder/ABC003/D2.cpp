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
// bの逆元求める
ll IE(ll b) {
  ll ret = 1;
  ll M = MOD - 2;
  for (; M; b = (b * b) % MOD, M >>= 1) {
    if(M & 1) ret = (ret * b) % MOD;
  }
  return ret % MOD;
}
// 組み合わせO(r)
ll nCr(ll n, ll r) {
  if(n < r) return 0;
  r = min(r, n - r);
  ll ret = 1;
  ll rr = r;
  for (ll i = n; i >= n - r + 1; i--) {
    ret = (ret * (i % MOD)) % MOD;
    ret = (ret * IE(rr)) % MOD;
    rr--;
  }
  return ret % MOD;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll R, C, X, Y, D, L;
  cin >> R >> C >> X >> Y >> D >> L;
  ll ans = nCr(X * Y, D + L);
  ans = (ans - 2 * nCr(X * (Y - 1), D + L) - 2 * nCr(Y * (X - 1), D + L) + 2 * MOD) % MOD;
  ans = (ans + 4 * nCr((X - 1) * (Y - 1), D + L)) % MOD;
  ans = (ans + nCr(max(X - 2, 0LL) * Y, D + L) + nCr(max(Y - 2, 0LL) * X, D + L)) % MOD;
  ans = (ans - 2 * nCr((X - 1) * max(Y - 2, 0LL), D + L) - 2 * nCr((Y - 1) * max(X - 2, 0LL), D + L) + 2 * MOD) % MOD;
  ans = (ans + nCr(max(X - 2, 0LL) * max(Y - 2, 0LL), D + L)) % MOD;
  ans *= nCr(D + L, D);
  ans = ans % MOD * (R - X + 1) % MOD * (C - Y + 1) % MOD;
  cout << ans % MOD << endl;
  return 0;
}