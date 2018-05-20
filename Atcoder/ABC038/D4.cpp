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
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
typedef pair<int,int> P;
//30点
//hで昇順ソートしてdp[i][j]:=i個目まででj個選んでる時のwの最小値
//100点
//seg tree->i<j、w[i]<w[j]、w[j]が一番外となる時の個数＝max(w[i]が一番外となる時の個数)+1

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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;cin>>N;
  int h[N],w[N];
  FOR(i,0,N)cin>>h[i]>>w[i];
  vector<P> v(N);
  FOR(i,0,N)v[i]=P(h[i],-w[i]);
  sort(v.begin(),v.end());
  segment_tree_max seg(100005);
  seg.set(0,0);
  ll ans=0;
  FOR(i,0,N){
    ll W=seg.get(0,-v[i].second)+1;
    seg.set(-v[i].second,W);
    ans=max(ans,W);
  }
  cout<<ans<<endl;
  return 0;
}
