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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m; cin >> n >> m;
  ll x[n]; FOR(i,0,n) cin >> x[i];
  ll y[m]; FOR(i,0,m) cin >> y[i];
  ll ans = 0;
  FOR(i,0,n-1) ans = (ans % MOD + (x[i+1] - x[i]) % MOD * (i + 1) % MOD * (n - i - 1)) % MOD;
  ll ans2 = 0;
  FOR(i,0,m-1) ans2 = (ans2 % MOD + (y[i+1] - y[i]) % MOD * (i + 1) % MOD * (m - i - 1)) % MOD;
  ans *= ans2;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}