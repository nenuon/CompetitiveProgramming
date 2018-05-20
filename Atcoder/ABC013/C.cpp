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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
const ll inf = 1e15;
// 二分探索
ll N, H;
ll A, B, C, D, E;
// k回飯を食う
ll calc(ll k) {
  ll ret = inf;
  // k1回普通の食事k2回質素
  // 二分探索で
  ll l = 0, r = k;
  FOR(i,0,100) {
    ll k1 = (r + l) / 2;
    ll k2 = k - k1;
    if(H - (N - k) * E + B * k1 + D * k2 > 0) {
      r = k1;
      ret = min(ret, k1 * A + k2 * C);
    } else {
      l = k1;
    }
  }
  if(H - (N - k) * E + B * k > 0) ret = min(ret, k * A);
  if(H - (N - k) * E + D * k > 0) ret = min(ret, k * C);
  return ret;
}

int main()
{
  cin >> N >> H;
  cin >> A >> B >> C >> D >> E;
  ll ans = inf;
  // k回食事する時
  FOR(k,0,N+1) ans = min(ans, calc(k));
  cout << ans << endl;
  return 0;
}
