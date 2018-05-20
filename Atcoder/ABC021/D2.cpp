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
const int MOD = 1e9+7;
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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k; cin >> n >> k;
  ll ans = 1;
  FOR(i,n,n+k) ans = (ans * (ll)i) % MOD;
  FOR(i,1,k+1) ans = (ans * IE(i)) % MOD;
  cout << ans << endl;
  return 0;
}