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
typedef pair<ll, ll> P;
ll dp[222][200005];
// N < 30では半分全列挙
// それ以外ではdpで解く
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, WMAX; cin >> N >> WMAX;
  ll v[N], w[N];
  ll mv = 0, mw = 0;
  FOR(i,0,N) {
    cin >> v[i] >> w[i];
    mv = max(mv, v[i]);
    mw = max(mw, w[i]);
  }

  // 半分全列挙で
  if(N <= 30) {
    int N2 = N / 2;
    vector<P> vec;
    FOR(i,0,1<<N2) {
      ll W = 0, V = 0;
      FOR(j,0,N2) {
        if((i>>j)&1) {
          W += w[j];
          V += v[j];
        }
      }
      vec.push_back(P(W, V));
    }
    sort(vec.begin(), vec.end());
    // 重さがm>iなのに価値がm<iならmはいらない
    // 重さm<iで価値がm<iとなるiのみ用いる
    int m = 1;
    FOR(i,1,1<<N2) {
      if(vec[m-1].second < vec[i].second) {
        vec[m++] = vec[i];
      }
    }
    ll ans = 0;
    FOR(i,0,1<<(N-N2)) {
      ll W = 0, V = 0;
      FOR(j,0,N-N2) {
        if((i>>j)&1) {
          W += w[j+N2];
          V += v[j+N2];
        }
      }
      if(W <= WMAX) {
        ll vv = (lower_bound(vec.begin(), vec.begin() + m, P(WMAX - W, 1e15)) - 1)->second;
        ans = max(ans ,vv + V);
      }
    }
    cout << ans << endl;
  }
  // dp[i][j] := i番目までで価値がjの時の重さの最小値
  else if(mv <= 1000){
    FOR(i,0,N+1) FOR(j,0,200005) dp[i][j] = 1e15;
    dp[0][0] = 0;
    FOR(i,0,N) {
      FOR(j,0,200005) {
        if(dp[i][j] == 1e15) continue;
        // 使う
        if(j + v[i] < 200005) dp[i+1][j+v[i]] = min(dp[i+1][j+v[i]], dp[i][j] + w[i]);
        // 使わない
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      }
    }
    int ans = 0;
    FOR(i,1,200001) if(dp[N][i] <= WMAX) ans = max(ans, i);
    cout << ans << endl;
  }
  // dp[i][j] := i番目までで重さがjの時の価値の最大値
  else {
    FOR(i,0,N+1) FOR(j,0,200005) dp[i][j] = -1;
    dp[0][0] = 0;
    FOR(i,0,N) {
      FOR(j,0,200005) {
        if(dp[i][j] == -1) continue;
        // 使う
        if(j + w[i] < 200005) dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
        // 使わない
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      }
    }
    ll ans = 0;
    FOR(i,0,WMAX+1) ans = max(ans, dp[N][i]);
    cout << ans << endl;
  }
  return 0;
}