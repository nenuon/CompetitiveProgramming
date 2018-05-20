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
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
const ll MOD = 1777777777;
ll N, K;
// bの逆元求める
ll IE(ll b) {
  ll ret = 1;
  ll M = MOD - 2;
  while(M)
  {
    if(M & 1) {
      ret *= b;
      ret %= MOD;
    }
    b *= b;
    b %= MOD;
    M >>= 1;
  }
  return ret % MOD;
}

// 組み合わせO(r)
ll C(ll n, ll r) {
  r = min(r, n - r);
  ll ret = 1;
  ll rr = r;
  for (ll i = n; i >= n - r + 1; i--)
  {
    ret = (ret * (i % MOD)) % MOD;
    ret = (ret * IE(rr)) % MOD;
    rr--;
  }
  return ret % MOD;
}

int main()
{
  cin >> N >> K;
  ll ans = C(N, K);
  ll a[K + 1];
  CLR(a);
  a[2] = 1;
  FOR(i,3,K+1) {
    a[i] = (i - 1) * ((a[i - 1] + a[i - 2]) % MOD);
    a[i] %= MOD;
  }
  ans *= a[K];
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
