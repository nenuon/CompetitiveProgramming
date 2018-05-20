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
int N, K;
vector<int> a;
bool dp[5050][5050];
// 不必要ならtrue
bool calc(int i) {
  vector<int> b;
  FOR(j,0,N) if(i != j) b.push_back(a[j]);
  CLR(dp);
  dp[0][0] = true;
  FOR(j,0,N-1) {
    FOR(k,0,K+1) {
      if(!dp[j][k]) continue;
      // b[j]を使う
      if(k+b[j] <= K) dp[j+1][k+b[j]] = true;
      // b[j]を使わない
      dp[j+1][k] = true;
    }
  }
  int wa = 0;
  FOR(j,0,K+1) {
    if(dp[N-1][j]) {
      wa = a[i] + j;
      if(wa >= K) break;
    }
  }
  return (wa < K) || (wa - a[i] >= K);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  a.resize(N);
  FOR(i,0,N) {
    int in; cin >> in;
    in = min(in, K);
    a[i] = in;
  }
  sort(a.begin(), a.end());
  int l = -1, r = N + 1;
  while(r - l > 1) {
    int m = (r + l) / 2;
    if(calc(m)) l = m;
    else r = m;
  }
  cout << min(r, N) << endl;
  return 0;
}