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
// 部分点
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K; cin >> N >> K;
  int a[N];
  FOR(i,0,N) {
    int in; cin >> in;
    in = min(in, K);
    a[i] = in;
  }
  if(N > 400 || K > 400) return 0;
  int ans = 0;
  // a[i]を含む集合について
  FOR(i,0,N) {
    vector<int> b;
    FOR(j,0,N) if(i != j) b.push_back(a[j]);
    bool dp[N][1000]; CLR(dp);
    dp[0][0] = true;
    FOR(j,0,N-1) {
      FOR(k,0,K+1) {
        if(!dp[j][k]) continue;
        // b[j]を使う
        dp[j+1][k+b[j]] = true;
        // b[j]を使わない
        dp[j+1][k] = true;
      }
    }
    int wa = 0;
    bool plus = false;
    FOR(j,0,1000) {
      if(dp[N-1][j]) {
        wa = a[i] + j;
        if(wa >= K) break;
      }
    }
    if(wa < K || wa - a[i] >= K) ans++;
  }
  cout << ans << endl;
  return 0;
}