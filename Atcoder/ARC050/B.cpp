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
// 二分探索
// K個作れるか
ll R, B, x, y;
ll calc(ll K) {
  return max(0LL, (R - K)) / (x - 1) + max(0LL, (B - K)) / (y - 1) >= K;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> B >> x >> y;
  ll l = 0, r = min(R, B) + 1;
  while(r - l > 1) {
    ll med = (l + r) / 2;
    if(calc(med)) l = med;
    else r = med;
  }
  cout << l << endl;
  return 0;
}