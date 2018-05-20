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
const ll MOD = 1777777777;
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
ll C(ll n, ll r) {
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
  ll N, K; cin >> N >> K;
  ll ans = C(N, K);
  // aは1~nの数字を並び替えた数列 a_i != iを満たす数列は何通りあるか 漸化式->f_k = (k-1)*(f_(k-1)+f_(k-2))
  ll f[K+1];
  f[1] = 0;
  f[2] = 1;
  FOR(i,3,K+1) f[i] = (ll)(i-1) * (f[i-1]+f[i-2]) % MOD;
  cout << ans * f[K] % MOD << endl;
  return 0;
}