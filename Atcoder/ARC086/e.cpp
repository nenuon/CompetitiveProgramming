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
vector<int> to[200005];
int dep[200005];
void dfs(int v, int d) {
  dep[v] = d;
  for(int nx : to[v]) {
    dfs(nx, d + 1);
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  ll P[N+1]; P[0] = -1;
  FOR(i,1,N+1) {
    ll p; cin >> p;
    P[i] = p;
    to[p].push_back(i);
  }
  dfs(0, 0);
  //FOR(i,0,N+1) cout << dep[i] << endl;
  ll ans = 0;
  FOR(i,0,N+1) {
    ll nosame = N + 1;
    //set<int> SET;
    ll can = 0;
    FOR(j,0,N+1) {
      if(dep[i] == dep[j]) {
        nosame--;
        if(P[i] != P[j] && to[P[j]].size() > 1) {
          can++;
        }
      }
    }
    
    //ans = (ans + SET.size()) % MOD;
    // ダブリング
    ll AA = 2;
    ll ans2 = 1;
    while(nosame) {
      if(nosame&1) ans2 = (ans2 * AA) % MOD;
      AA = (AA * AA) % MOD; 
      nosame >>= 1;
    }
    ans = (ans + ans2) % MOD;
    //cout << nosame2 << endl;
    ll nosame2 = N;
    if(can > 0) {
      // ダブリング
      AA = 2;
      ans2 = 1;
      nosame2 -= can;
      while(nosame2) {
        if(nosame2 & 1) ans2 = (ans2 * AA) % MOD;
        AA = (AA * AA) % MOD; 
        nosame2 >>= 1;
      }
      ans = (ans + ans2) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}