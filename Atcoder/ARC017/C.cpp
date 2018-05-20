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
// 半分全列挙
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, X; cin >> N >> X;
  ll w[N]; FOR(i,0,N) cin >> w[i];
  map<ll, int> MAP;
  int N2 = N / 2;
  FOR(i,0,1<<N2) {
    ll x = 0;
    FOR(j,0,N2) {
      if((i>>j)&1) {
        x += w[j];
      }
    }
    MAP[x]++;
  }
  int ans = 0;
  FOR(i,0,1<<(N-N2)) {
    ll x = 0;
    FOR(j,0,(N-N2)) {
      if((i>>j)&1) {
        x += w[N2 + j];
      }
    }
    ans += MAP[X - x];
  }
  cout << ans << endl;
  return 0;
}
