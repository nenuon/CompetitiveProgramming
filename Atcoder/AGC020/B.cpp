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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll K; cin >> K;
  ll A[K]; FOR(i,0,K) cin >> A[i];
  ll x = 2;
  ll y = 3;
  for(int i = K - 1; i >= 0; i--) {
    // 最小
    x = (x + A[i] - 1) / A[i] * A[i];


    // 最大
    y = (y / A[i] + 1) * A[i] - 1;
  }
  ll ans = x;
  FOR(i,0,K) {
    x = x / A[i] * A[i];
  }
  if(x == 2) {
    cout << ans << " " << y << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}