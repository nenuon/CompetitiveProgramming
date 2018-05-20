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
  int N; cin >> N;
  int tmax = 0;
  int t[N+2]; FOR(i,0,N) cin >> t[i+1], tmax += t[i+1];
  int v[N+2]; FOR(i,0,N) cin >> v[i+1];
  v[0] = v[N+1] = 0;
  t[0] = t[N+1] = 0;
  double l[2*tmax+1], r[2*tmax+1];
  l[0] = 0;
  r[2*tmax] = 0;
  CLR(l);CLR(r);
  int i = 1;
  int T = 0;
  FOR(k,0,N+1) {
    T += t[k];
    while(i <= (T + t[k+1]) * 2) {
      l[i] = min(l[i-1] + 0.5, (double)v[k+1]);
      i++;
    }
  }
  T = 0;
  i = 1;
  for(int k = N + 1; k > 0; k--) {
    T += t[k];
    while(i <= (T + t[k-1]) * 2) {
      r[2 * tmax - i] = min(r[2 * tmax - i + 1] + 0.5, (double)v[k-1]);
      i++;
    }
  }
  // FOR(i,0,tmax+1) cout << l[i] << " " << r[i] << endl;
  double ans = 0;
  FOR(i,0,2*tmax) {
    ans += (min(l[i], r[i]) + min(l[i+1], r[i+1])) * 0.25;
  }
  printf("%.10lf\n", ans);
  return 0;
}