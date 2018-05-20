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
const double EPS = 1e-10;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int x[N], y[N];
  FOR(i,0,N) cin >> x[i] >> y[i];
  int cho = 0, don = 0;
  // B
  FOR(i,0,N) {
    vector<double> a;
    FOR(j,0,N) if(j != i) a.push_back(atan2(y[j]-y[i],x[j]-x[i]));
    sort(a.begin(), a.end());
    // -の角度を+にする
    FOR(j,0,N-1) a.push_back(a[j] + M_PI * 2);
    FOR(j,0,N-1) {
      int x = lower_bound(a.begin(), a.end(), a[j] + M_PI / 2 - EPS) - a.begin();
      int y = upper_bound(a.begin(), a.end(), a[j] + M_PI / 2 + EPS) - a.begin();
      int z = lower_bound(a.begin(), a.end(), a[j] + M_PI) - a.begin();
      cho += y - x;
      don += z - y;
    }
  }
  int ei = (ll)N * (N - 1) * (N - 2) / 6 - cho - don;
  cout << ei << " " << cho << " " << don << endl;
  return 0;
}