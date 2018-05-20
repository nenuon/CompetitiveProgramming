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
const ll MOD = 1000000007;
// bの逆元求める
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
  ll A, B, C; cin >> A >> B >> C;
  ll AB = A * B % MOD;
  ll BC = B * C % MOD;
  ll CA = C * A % MOD;
  ll c = (BC - AB + MOD) % MOD;
  c *= IE(CA - BC + AB + MOD);
  c %= MOD;
  ll r = (BC - CA + MOD) % MOD;
  r *= IE(AB - BC + CA + MOD);
  r %= MOD;
  cout << r << " " << c << endl;
  return 0;
}