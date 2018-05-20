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
// セグメント木 [i,j)の最小値をlognで
const int NMAX = 1 << 18;
ll N, n, dat[2*NMAX-1];
void init(int n_) {
  n = 1;
  while(n < n_) n *= 2;
  FOR(i,0,2*n-1) dat[i] = 1e9;
}
// kの位置にaを追加
void update(int k, int a) {
  k += n - 1;
  dat[k] = a;
  while(k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k*2+1],dat[k*2+2]);
  }
}
// [l,r)の中での最小値query(l,r,0,0,n)
int query(int a, int b, int k, int l, int r) {
  if(r <= a || b <= l) return 1e9;
  if(a <= l && r <= b) return dat[k];
  else {
    int vl = query(a,b,k*2+1,l,(l+r)/2);
    int vr = query(a,b,k*2+2,(l+r)/2,r);
    return min(vl, vr);
  }
}
typedef pair<int, int> P;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int H[N], W[N];
  FOR(i,0,N) {
    int w, h; cin >> w >> h;
    box[i] = P(h, -w);
  }
  sort(box.begin(), box.end());
  int dp[N]; CLR(0);
  init(N+1);
  int ans = 0;
  FOR(i,0,N) {
    dp[i] = query(0, -v[i].second, 0, 0, N+1) + 1;
    update(-v[i].second, dp[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}