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
vector<vector<int> > G(100005);
int dfs(int v, int goal, int par) {
  if(v == goal) return 1;
  int ret = 0;
  for(auto &to : G[v]) {
    if(to == par) continue;
    ret += dfs(to, goal, v);
  }
  if(ret > 0) ret++;
  return ret;
}

int main()
{
  int N; cin >> N;
  FOR(i,0,N-1) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int Q; cin >> Q;
  if(Q != 1) return 0;
  int a, b; cin >> a >> b;
  cout << dfs(a, b, 0) << '\n';
  return 0;
}
