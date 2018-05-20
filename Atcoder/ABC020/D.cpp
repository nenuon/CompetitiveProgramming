
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
const int mod = 1e9 + 7;
//最大公約数
ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) a %= b;
    else b %= a;
  }
  return a + b;
}
//最小公倍数
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b;}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, K; cin >> N >> K;
  ll ans = 0;
  if(K > 100) return 0;
  FOR(i,0,K) {
    if(i > N) break;
    ll n = N / K;
    ll r = n * K + i;
    if(r > N) {
      r -= K;
    } else {
      n++;
    }
    ans += n * (i + r) / 2 / gcd(i, K) * K;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
