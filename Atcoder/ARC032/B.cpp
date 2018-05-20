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
// 連結成分の個数-1
vector<vector<int> > G(100005);
bool visited[100005];
void dfs(int x) {
  visited[x] = true;
  for(auto to : G[x]) {
    if(!visited[to]) dfs(to);
  }
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
      dfs(i);
      ans++;
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
