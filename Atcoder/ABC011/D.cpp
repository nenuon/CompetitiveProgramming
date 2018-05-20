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
typedef pair<double, P> PP;
int main()
{
  int N, D, X, Y;
  cin >> N >> D >> X >> Y;
  queue<PP> Q;
  Q.push(PP(1.0, P(0, 0)));
  ll vy[4] = {-D, 0, D, 0};
  ll vx[4] = {0, D, 0, -D};
  while(1) {
    map<P, double> MAP;
    while(!Q.empty()) {
      PP pp = Q.front();Q.pop();
      P p = pp.second; // 座標
      FOR(i,0,4) {
        ll ny = p.first + vy[i];
        ll nx = p.second + vx[i];
        MAP[P(ny, nx)] += pp.first / 4.0;
      }
    }
    N--;
    if(N == 0) {
      printf("%.010lf\n", MAP[P(Y,X)]);
      return 0;
    }
    for(auto itr = MAP.begin(); itr != MAP.end(); itr++) {
      Q.push(PP(itr->second, itr->first));
    }
  }
  return 0;
}
