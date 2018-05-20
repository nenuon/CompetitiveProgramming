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
// 距離の2乗
int calc(int x1, int y1, int x2, int y2) {
  return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}
double EPS = 1e-10;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<ll> x(N), y(N);
  FOR(i,0,N) cin >> x[i] >> y[i];
  ll cho = 0, don = 0;
  FOR(i,0,N) {
    vector<double> a;
    FOR(j,0,N) {
      if(j != i) a.push_back(atan2(y[j] - y[i], x[j] - x[i]));
    }
    sort(a.begin(), a.end());
    FOR(j,0,N-1) a.push_back(a[j] + M_PI * 2); // +の角度にする
    FOR(j,0,N-1) {
      int x = lower_bound(a.begin(), a.end(), a[j] + M_PI / 2 - EPS) - a.begin();
      int y = upper_bound(a.begin(), a.end(), a[j] + M_PI / 2 + EPS) - a.begin();
      int z = lower_bound(a.begin(), a.end(), a[j] + M_PI) - a.begin();
      cho += y - x;
      don += z - y;
    }
  }
  ll ei = (ll)N * (N - 1) * (N - 2) / 6 - cho - don;
  cout << ei << " " << cho << " " << don << endl;
  return 0;
}