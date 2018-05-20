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
#include <random>
#include <time.h>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
typedef pair<int, int> P;

int main()
{
  int N, M;
  cin >> N >> M;
  if(N > 5000 && M > 5000) return 0;
  vector<P> haba(N);
  bool used[M+1];
  FOR(i,0,M+1) used[i] = false;
  int s[N];
  FOR(i,0,N) {
    int l, r;
    cin >> l >> r >> s[i];
    haba[i] = P(l, r);
    FOR(j,l,r+1) used[j] = true;
  }
  // 最初から重ならない場合
  FOR(i,1,M+1) {
    if(!used[i]) {
      int sum = 0;
      FOR(j,0,N) sum += s[j];
      cout << sum << endl;
      return 0;
    }
  }
  // i を使わない場合
  int ans = 0;
  FOR(i,1,M+1) {
    int cnt = 0;
    FOR(j,0,N) {
      if(haba[j].first <= i && i <= haba[j].second) continue;
      cnt += s[j];
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
