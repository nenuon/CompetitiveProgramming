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
int N;
int d_fe[100005], d_su[100005];
vector<vector<int> > G;

void dfs_fe(int x, int d, int par) {
  d_fe[x] = d;
  for(auto to : G[x]) {
    if(to == par) continue;
    dfs_fe(to,d+1,x);
  }
  return;
}
void dfs_su(int x, int d, int par) {
  d_su[x] = d;
  for(auto to : G[x]) {
    if(to == par) continue;
    dfs_su(to,d+1,x);
  }
  return;
}

int main()
{
  cin >> N;
  G.resize(N);
  FOR(i,0,N-1) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs_fe(0,0,-1);
  dfs_su(N-1,0,-1);
  int cnt = 0;
  FOR(i,0,N) {
    if(d_fe[i] <= d_su[i]) cnt++;
  }
  cout << (cnt > N - cnt ? "Fennec" : "Snuke") << endl;
  return 0;
}
