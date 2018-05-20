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
const int MOD = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int P[N+1]; P[0] = -1;
  FOR(i,1,N+1) {
    cin >> P[i];
  }
  ll ans = 0;
  FOR(i,0,N+1) {
    int nosame = N + 1;
    FOR(j,0,N+1) {
      if(P[i] == P[j]) nosame--;
    }
    // ダブリング
    ll AA = 2;
    ll ans2 = 1;
    while(nosame) {
      if(nosame&1) ans2 = (ans2 * AA) % MOD;
      AA = (AA * AA) % MOD; 
      nosame >>= 1;
    }
    ans = (ans + ans2) % MOD;
  }
  cout << ans << endl;
  return 0;
}