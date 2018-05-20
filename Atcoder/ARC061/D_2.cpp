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
typedef pair<ll, ll> P;
int main()
{
  ll H, W, N; cin >> H >> W >> N;
  map<P, int> MAP;
  int vy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
  int vx[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
  FOR(i,0,N) {
    ll y, x; cin >> y >> x;
    y--;x--;
    FOR(j,0,9) {
      ll ny = y + vy[j];
      ll nx = x + vx[j];
      if(ny <= 0 || ny >= H - 1 || nx <= 0 || nx >= W - 1) continue;
      MAP[P(ny, nx)]++;
    }
  }
  ll ans[10]; CLR(ans);
  for(auto itr = MAP.begin(); itr != MAP.end(); itr++) {
    ans[itr->second]++;
  }
  ans[0] = (H - 2) * (W - 2);
  FOR(i,1,10) ans[0] -= ans[i];
  FOR(i,0,10) cout << ans[i] << endl;
  return 0;
}
