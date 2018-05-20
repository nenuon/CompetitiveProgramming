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
int N, M; 
vector<vector<int> > G(100005);
bool visited[100005];
deque<int> ans;
void dfs(int x, int f) {
  if(f) ans.push_front(x);
  else ans.push_back(x);
  visited[x] = true;
  for(int to : G[x]) {
    if(visited[to]) continue;
    dfs(to, f);
    break;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  FOR(i,0,M) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1, 1);
  dfs(1, 0);
  cout << ans.size() - 1 << endl;
  FOR(i,0,ans.size()) {
    cout << ans[i] << " ";
    if(ans[i] == 1) i++;
  }
  cout << endl;
  return 0;
}