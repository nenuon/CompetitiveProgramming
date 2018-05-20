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
// セグメント木
struct segment_tree_max {
	int n; vector<ll> v;
	segment_tree_max(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<ll>(n * 2 - 1, -1e9);
	}
	void set(int i, ll x) {
		int k = i + n - 1;
		v[k] = max(v[k], x);
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = max(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	ll _get(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return -1e9;
		if (i <= l && r <= j) return v[k];
		ll vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		ll vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	ll get(int i, int j) { return _get(i, j, 0, 0, n); }
};
typedef pair<int, int> P;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<P> box(N);
  FOR(i,0,N) {
    int h, w; cin >> h >> w;
    box[i] = P(h, -w);
  }
  sort(box.begin(), box.end());
  int ans = 0;
  int dp[N]; CLR(dp);
  segment_tree_max stm(100005);
  stm.set(0, 0);
  FOR(i,0,N) {
    dp[i] = stm.get(0, -box[i].second) + 1;
    stm.set(-box[i].second, dp[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}