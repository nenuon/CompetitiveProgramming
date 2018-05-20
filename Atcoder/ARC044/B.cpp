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
const int MOD = 1000000007;
ll d[100005];
// xのp乗(p>=0)
ll calc(ll x, ll p) {
  ll ret = 1;
  while(p>0) {
    if(p&1) ret *= x;
    x *= x;
    x %= MOD;
    ret %= MOD;
    p >>= 1;
  }
  return ret;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  bool ok = true;
  int mx = 0;
  FOR(i,1,N+1) {
    int in;
    cin >> in;
    d[in]++;
    if(i == 1 && in != 0) ok = false;
    if(i != 1 && in == 0) ok = false;
    mx = max(mx, in);
  }
  FOR(i,0,mx+1) {
    if(d[i] == 0) ok = false;
  } 
  if(!ok) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  FOR(i,1,mx+1) {
    ans *= calc(calc(2, d[i - 1]) - 1, d[i]);
    ans %= MOD;
    ans *= calc(2, d[i] * (d[i] - 1) / 2);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}