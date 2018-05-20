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
#define FOR(I,A,B) for(long long I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
ll f(ll b, ll n) {
  if(n < b) return n;
  else return f(b, n / b) + n % b;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, s;
  cin >> n >> s;
  ll ans = 1e15;
  if(n == s) {
    cout << n + 1 << endl;
    return 0;
  } else {
    FOR(b,2,sqrt(n)+1) {
      if(f(b, n) == s) {
        cout << b << endl;
        return 0;
      }
    }
  }
    FOR(p,1,sqrt(n)+1) {
      ll q = s - p;
      if(q < 0) continue;
      if((n - q) % p != 0) continue;
      ll b = (n - q) / p;
      if(b <= 1) continue;
      if(f(b, n) == s) ans = min(ans, b);
    }
  if(ans == 1e15) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}