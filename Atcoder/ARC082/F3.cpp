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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll X, K; cin >> X >> K;
  ll r[K+1]; FOR(i,1,K+1) cin >> r[i];
  r[0] = 0;
  ll Q; cin >> Q;
  ll mx = X, mn = 0;
  int j = 1;
  ll d = 0;
  FOR(i,0,Q) {
    ll t, a; cin >> t >> a;
    while(j <= K && r[j] <= t) {
      if(j % 2 == 1) {
        mx = max(0LL, mx - (r[j] - r[j-1]));
        mn = max(0LL, mn - (r[j] - r[j-1]));
        d -= (r[j] - r[j-1]);
      } else {
        mx = min(X, mx + (r[j] - r[j-1]));
        mn = min(X, mn + (r[j] - r[j-1]));
        d += (r[j] - r[j-1]);
      }
      j++;
    }
    ll dd = min(mx, max(mn, a + d)) + (j % 2 == 1 ? - (t - r[j-1]) : (t - r[j-1]));
    cout << max(min(dd, X), 0LL) << endl;
  }
  return 0;
}