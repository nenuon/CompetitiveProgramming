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
vector<vector<int> > G(111);
int ans, n, x;
int h[111]; 
bool dfs(int v, int par) {
  bool ret = h[v] ;
  for(auto to : G[v]) {
    if(to == par) continue;
    ret |= dfs(to, v);
  }
  if(ret && v != x) ans += 2;
  return ret;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x;
  FOR(i,1,n+1) cin >> h[i];
  FOR(i,0,n-1) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(x, 0);
  cout << ans << endl;
}