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
const int mod = 1000000007;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M; cin >> N >> M;
  int f[N+1]; FOR(i,1,N+1) cin >> f[i];
  f[0] = 0;
  int r[M+1]; FOR(i,0,M+1) r[i] = -1; // iが出る一番右側
  r[0] = 0;
  ll wa[N+2]; CLR(wa);
  wa[0] = 0;
  int l = 0; // 同じ数字が2回出る左端
  ll dp[N+1]; CLR(dp);
  dp[0] = 1;
  wa[1] = 1;
  FOR(i,1,N+1) {
    if(l < r[f[i]]) l = r[f[i]];
    r[f[i]] = i;
    dp[i] += (wa[i] - wa[l] + mod) % mod;
    dp[i] %= mod;
    wa[i+1] = (wa[i] + dp[i]) % mod;
  }
  cout << dp[N] << endl;
  return 0;
}