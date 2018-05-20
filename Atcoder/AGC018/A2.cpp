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
//最大公約数
ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) a %= b;
    else b %= a;
  }
  return a + b;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, K; cin >> N >> K;
  ll A[N];
  ll mx = 0;
  FOR(i,0,N) {
    cin >> A[i];
    mx = max(mx, A[i]);
  }
  int g = gcd(A[0], A[1]);
  FOR(i,2,N) g = gcd(g, A[i]);
  if(K <= mx && (mx - K) % g == 0) puts("POSSIBLE");
  else puts("IMPOSSIBLE");
  return 0;
}
