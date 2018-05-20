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

int main()
{
  int N, M;
  cin >> N >> M;
  bool g[N][N]; CLR(g);
  FOR(i,0,M) {
    int x, y;
    cin >> x >> y;
    x--;y--;
    g[y][x] = true;
  }
  ll dp[(1<<N)]; CLR(dp);
  dp[0] = 1;
  FOR(i,1,(1<<N)) {
    vector<int> S;
    FOR(j,0,N) if((i>>j)&1) S.push_back(j);
    // v -> S - {v} に向かう有向辺があるかどうか
    FOR(k,0,S.size()) {
      bool ok = true;
      FOR(l,0,S.size()) {
        if(S[k] == S[l]) continue;
        if(g[S[k]][S[l]]) ok = false;
      }
      if(ok) dp[i] += dp[i^(1LL<<S[k])];
    }
  }
  cout << dp[(1<<N)-1] << endl;
  return 0;
}
