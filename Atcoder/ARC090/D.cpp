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
struct edge{
  int to, cost;
  edge(int t, int c) {
    to = t, cost = c;
  }
};
int dist[100005];
vector<edge> G[100005];

void dfs(int v, int d) {
  if(dist[v] == 2e9) {
    dist[v] = d;
    for(auto to : G[v]) {
      dfs(to.to, d + to.cost);
    }
  } else {
    if(dist[v] != d) {
      cout << "No" << endl;
      exit(0);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  FOR(i,0,M) {
    int l,r,d;
    cin >> l >> r >> d;
    G[l].push_back(edge(r, d));
    G[r].push_back(edge(l, -d));
  }
  FOR(i,0,N+1) dist[i] = 2e9;
  FOR(i,1,N+1) {
    if(dist[i] == 2e9) {
      dfs(i, 0);
    }
  }
  cout << "Yes" << endl;
  return 0;
}