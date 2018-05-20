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
typedef long long ll;
int dp[50][500][500];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N,Ma,Mb;cin>>N>>Ma>>Mb;
  int a[N],b[N],c[N];
  FOR(i,0,N) cin >> a[i] >> b[i] >> c[i];
  FOR(i,0,N+1) FOR(j,0,500) FOR(k,0,500) dp[i][j][k] = 1e9;
  dp[0][0][0] = 0;
  FOR(i,0,N) {
    FOR(j,0,401) {
      FOR(k,0,401) {
        if(dp[i][j][k] == 1e9) continue;
        // iを混ぜる
        dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]);
        // 混ぜない
        dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
      }
    }
  }
  int ans = 1e9;
  FOR(i,1,500) FOR(j,1,500) if(i*Mb==j*Ma) ans = min(ans, dp[N][i][j]);
  cout << (ans == 1e9 ? -1 : ans) << endl;
  return 0;
}