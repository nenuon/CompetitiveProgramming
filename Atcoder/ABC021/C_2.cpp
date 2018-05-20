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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
typedef pair<int, ll> pint;
const int inf = 1e9;
const int mod = 1e9+7;

struct edge{
  int to, cost;
  edge(int t, int c) {
    to = t, cost = c;
  }
};
int a, b, N, M;
ll dp[111];
bool visited[111];
vector<edge> G[111];
int main()
{
  cin >> N;
  cin >> a >> b;
  cin >> M;
  FOR(i,0,M) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(edge(y, 1));
    G[y].push_back(edge(x, 1));
  }
  // 幅優先
  priority_queue<pint> Q; // 場所、何通りか
  set<int> SET;
  FOR(i,0,111) dp[i] = 0;
  FOR(i,0,111) visited[i] = false;
  Q.push(pint(a,1));
  FOR(i,0,1000000) {
    while(!Q.empty()) {
      pint q = Q.top();Q.pop();
      dp[q.first] += q.second;
      dp[q.first] %= mod;
      visited[q.first] = true;
      SET.insert(q.first);
    }
    if(dp[b] > 0) break;
    for(auto &v : SET) {
      for(auto &to : G[v]) {
        if(visited[to.to]) continue;
        Q.push(pint(to.to, dp[v]));
      }
    }
  }
  cout << dp[b] << endl;
  return 0;
}
