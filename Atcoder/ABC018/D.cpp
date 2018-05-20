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
struct edge{
  int to, cost;
  edge(int t, int c) {
    to = t, cost = c;
  }
};
vector<edge> G[20];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M, P, Q, R;
  cin >> N >> M >> P >> Q >> R;
  FOR(i,0,R) {
    int x, y , z;
    cin >> x >> y >> z;
    G[x].push_back(edge(y, z));
  }
  int ans = 0;
  FOR(i,0,1<<N) {
    vector<int> g; // 選ぶ女子
    FOR(j,0,N) {
      if((i>>j)&1) {
        g.push_back(j+1);
      }
    }
    if(g.size() != P) continue;
    int b[M+1]; CLR(b);
    FOR(j,0,P) {
      for(auto e : G[g[j]]) {
        b[e.to] += e.cost;
      }
    }
    sort(b, b + M + 1);
    reverse(b, b + M + 1);
    int sum = 0;
    FOR(j,0,Q) sum += b[j];
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}