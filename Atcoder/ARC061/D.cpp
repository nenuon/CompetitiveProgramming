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
typedef pair<ll, ll> P;
ll H, W, N;
// ますが多いので(y,x)周りに何個黒があるかをマップで管理
map<P, int> MAP;
int main(){
  cin >> H >> W >> N;
  int vy[9] = {0,-1,-1,0,1,1,1,0,-1};
  int vx[9] = {0,0,1,1,1,0,-1,-1,-1};
  ll cnt = 0;
  FOR(i,0,N) {
    ll y, x;
    cin >> y >> x;
    FOR(j,0,9) {
      if(y+vy[j]<=1||y+vy[j]>=H||x+vx[j]<=1||x+vx[j]>=W) continue;
      MAP[P(y+vy[j],x+vx[j])]++;
    }
  }
  ll ans[10];
  FOR(i,0,10) ans[i] = 0;
  for(auto itr = MAP.begin(); itr != MAP.end(); itr++) {
    ans[itr->second]++;
  }
  ans[0] = (W - 2) * (H - 2);
  FOR(i,1,10) ans[0] -= ans[i];
  FOR(i,0,10) cout << ans[i] << endl;
  return 0;
}
