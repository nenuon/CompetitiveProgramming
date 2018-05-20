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
// 親以外にvisitedがあったらループしてる
bool visited[111];
vector<vector<int> > G(111);
bool tree(int x, int par) {
  visited[x] = true;
  bool ret = true;
  for(int to : G[x]) {
    if(to == par) continue;
    if(visited[to]) return false;
    ret &= tree(to, x);
  }
  return ret;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  CLR(visited);
  int N, M; cin >> N >> M;
  FOR(i,0,M) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int ans = 0;
  FOR(i,1,N+1) {
    if(!visited[i]) {
      ans += tree(i, -1);
    }
  }
  cout << ans << endl;
  return 0;
}
