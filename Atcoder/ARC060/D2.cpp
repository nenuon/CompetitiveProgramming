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
ll f(ll b, ll n) {
  if(n < b) return n;
  return f(b, n / b) + n % b;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, s; cin >> n >> s;
  if(n < s) {
    cout << -1 << endl;
    return 0;
  }
  if(n == s) {
    cout << n + 1 << endl;
    return 0;
  }
  ll ans = 1e15;
  for(ll b = 2; b * b <= n; b++) {
    if(f(b, n) == s) {
      cout << b << endl;
      return 0;
    }
  }
  // b > sqrt(n)の時
  for(ll p = 1; p * p < n; p++) {
    if((n-s) % p == 0) {
      ll b = (n - s) / p + 1;
      if(f(b, n) == s) ans = min(ans, b);
    }
  }
  cout << (ans == 1e15 ? -1 : ans) << endl;
  return 0;
}