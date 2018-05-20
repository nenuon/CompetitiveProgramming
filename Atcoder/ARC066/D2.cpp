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
typedef pair<ll, ll> P;
const int MOD = 1000000007;
map<P, ll> MAP;
ll f(ll S, ll T) {
  if(MAP.count(P(S, T))) return MAP[P(S, T)];
  if(S < 0 || T < 0) return 0;
  if(S == 0 && T == 0) return 1;
  ll ret = f(S / 2, T / 2);
  if(S > 0 && T > 0) ret += f((S - 1) / 2, (T - 1) / 2);
  if(T > 1) ret += f(S / 2, (T - 2) / 2);
  return MAP[P(S, T)] = ret % MOD;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  cout << f(N, N) << endl;
  return 0;
}