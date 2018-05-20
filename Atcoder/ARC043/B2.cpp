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
const int MOD = 1000000007;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;cin >> N;
  vector<int> D(N); FOR(i,0,N) cin >> D[i];
  sort(D.begin(), D.end());
  int high[N]; CLR(high);
  int low[N]; CLR(low);
  FOR(i,0,N) {
    high[i] = N - (lower_bound(D.begin(), D.end(), D[i] * 2) - D.begin());
    low[i] = upper_bound(D.begin(), D.end(), D[i] / 2) - D.begin();
  }
  int sum[N+1];
  sum[0] = 0;
  FOR(i,0,N) sum[i+1] = (sum[i] + high[i]) % MOD;
  ll ans = 0;
  FOR(i,0,N) {
    int j = lower_bound(D.begin(), D.end(), D[i] * 2) - D.begin();
    ans += (ll)low[i] * (ll)(sum[N]-sum[j]);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}