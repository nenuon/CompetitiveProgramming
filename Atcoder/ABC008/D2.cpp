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
typedef pair<int, int> P;
typedef pair<P, P> PP;
int W, H, N;
vector<P> v(30);
map<PP, ll> MAP;
ll dfs(int x1, int y1, int x2, int y2) {
  if(MAP.count(PP(P(x1,y1),P(x2,y2)))) return MAP[PP(P(x1,y1),P(x2,y2))];
  ll ret = 0;
  FOR(i,0,N) {
    int X = v[i].first;
    int Y = v[i].second;
    ll tmp = 0;
    if(X >= x1 && X <= x2 && Y >= y1 && Y <= y2) {
      tmp = y2 - y1 + x2 - x1 + 1;
      tmp += dfs(x1,Y+1,X-1,y2); // 左上
      tmp += dfs(X+1,Y+1,x2,y2); // 右上
      tmp += dfs(x1,y1,X-1,Y-1); // 左下
      tmp += dfs(X+1,y1,x2,Y-1); // 右下 
    }
    ret = max(ret, tmp);
  }
  MAP[PP(P(x1,y1), P(x2,y2))] = ret;
  return ret;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> W >> H >> N;
  FOR(i,0,N) {
    int x, y; cin >> x >> y;
    v[i] = P(x, y);
  }
  cout << dfs(1,1,W,H) << endl;
  return 0;
}