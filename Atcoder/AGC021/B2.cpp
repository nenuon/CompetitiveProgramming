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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define PI acos(-1)
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> x(N), y(N);
  FOR(i,0,N) cin >> x[i] >> y[i];
  FOR(i,0,N) {
    vector<double> ang;
    FOR(j,0,N) {
      if(i != j) {
        ang.push_back(atan2(y[j]-y[i], x[j]-x[i]));
      }
    }
    sort(ang.begin(), ang.end());
    double mx = 0.0;
    FOR(j,0,ang.size()-1) {
      mx = max(mx, ang[j+1]-ang[j]);
    }
    mx = max(mx, ang[0] + 2 * PI - ang[ang.size()-1]);
    double ans = mx > PI ? (mx - PI) / 2 / PI : 0.0;
    cout << fixed << setprecision(17) << ans << endl;
  }
  return 0;
}