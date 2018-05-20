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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
const int NMAX = 1 << 18;
ll N, n, dat[2*NMAX-1];
void init(int n_) {
  n = 1;
  while(n < n_) n *= 2;
  FOR(i,0,2*n-1) dat[i] = 1e9;
}
void update(int k, int a) {
  k += n - 1;
  dat[k] = a;
  while(k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k*2+1],dat[k*2+2]);
  }
}
int query(int a, int b, int k, int l, int r) {
  if(r <= a || b <= l) return 1e9;
  if(a <= l && r <= b) return dat[k];
  else {
    int vl = query(a,b,k*2+1,l,(l+r)/2);
    int vr = query(a,b,k*2+2,(l+r)/2,r);
    return min(vl, vr);
  }
}

int mnidx[200005]; // 数字 - > インデックス

ll dfs(ll l, ll r) {
  if(r - l < 0) return 0;
  int mn = query(l,r+1,0,0,n);
  ll i = mnidx[mn];
  ll ret = mn * (i - l + 1) * (r - i + 1);
  ret += dfs(i+1,r);
  ret += dfs(l,i-1);
  return ret;
}

int main()
{
  cin >> N;
  init(N);
  FOR(i,0,N+1) mnidx[i] = 0;
  FOR(i,0,N) {
    int a;
    cin >> a;
    mnidx[a] = i;
    update(i,a);
  }
  cout << dfs(0,N-1) << endl;
  return 0;
}
