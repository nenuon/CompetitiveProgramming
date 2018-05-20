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
  int N, K; cin >> N >> K;
  ll x[N], y[N];
  FOR(i,0,N) cin >> x[i] >> y[i];
  ll ans = 4e18;
  // x方向2つの点
  FOR(i,0,N) {
    FOR(j,0,N) {
      if(i == j || x[i] >= x[j]) continue;
      // y方向2つの点
      FOR(k,0,N) {
        FOR(l,0,N) {
          if(k == l || y[k] <= y[l]) continue; 
          if(x[i] <= x[k] && x[j] >= x[k] && x[i] <= x[l] && x[j] >= x[l]) {
            if(y[i] <= y[k] && y[i] >= y[l] && y[j] <= y[k] && y[j] >= y[l]) {
              int cnt = 0;
              FOR(c,0,N) {
                if(x[c] >= x[i] && x[c] <= x[j] && y[c] <= y[k] && y[c] >= y[l]) cnt++;
              }
              if(cnt >= K) {
                ans = min(ans, (x[j] - x[i]) * (y[k] - y[l]));
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}