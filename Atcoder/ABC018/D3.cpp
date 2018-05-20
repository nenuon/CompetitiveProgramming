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
  int N,M,P,Q,R;
  cin>>N>>M>>P>>Q>>R;
  int G[N][M]; CLR(G);
  FOR(i,0,R) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;y--;
    G[x][y] = z;
  }
  int ans = 0;
  FOR(i,0,1<<N) {
    vector<int> g;
    FOR(j,0,N) {
      if((i>>j)&1) g.push_back(j);
    }
    if(g.size() == P) {
      int b[M]; CLR(b);
      FOR(k,0,g.size()) {
        FOR(l,0,M) {
          b[l] += G[g[k]][l];
        }
      }
      sort(b, b + M);
      reverse(b, b + M);
      int cnt = 0;
      FOR(k,0,Q) cnt += b[k];
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;
  return 0;
}