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
ll f(ll a, ll b) {
  ll mx = max(a, b);
  ll mn = min(a, b);
  if(mn == mx) return mx;
  if(mx % mn == 0) return 2 * mx - mn;
  return 2 * mn * (mx / mn) + f(mn, mx % mn);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, X; cin >> N >> X;
  cout << N + f(X, N - X) << endl;
  return 0;
}