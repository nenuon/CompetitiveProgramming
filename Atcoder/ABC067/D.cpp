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
vector<vector<int> > g;
vector<int> st; // 1->Nの最短で通る頂点
int num[100005];

bool dfs(int x, int par) {
  num[x] = 1;
  bool ret = false;
  for(int to : g[x]) {
    if(to == par) continue;
    ret |= dfs(to, x);
    num[x] += num[to];
  }
  if(x==N-1) ret = true;
  if(ret) st.push_back(x);
  return ret;
}

int main()
{
  cin>>N;
  g.resize(N);
  FOR(i,0,N-1) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  //st.push_back(N-1);
  bool ok = dfs(0,-1);
  int sunuke = num[st[st.size()/2-1]];
  int fenec = N - sunuke;
  cout << (sunuke >= fenec ? "Snuke" : "Fennec") << endl;
  return 0;
}
