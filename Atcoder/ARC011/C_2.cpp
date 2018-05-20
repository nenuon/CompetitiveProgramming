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
const int inf = 1e9;
map<string, int> MAP;
map<int, string> PAM;
int come[2005];
// ダイクストラ
struct edge{
  int to, cost;
  edge(int t, int c) {
    to = t, cost = c;
  }
};
typedef pair<int, int> P;
int N;
vector<edge> G[2005];
int d[2005];
void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P> >que;
  FOR(i,0,2005) d[i] = inf;
  d[s] = 0;
  que.push(P(0, s));
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(auto &e : G[v]){
      if(d[e.to] > d[v] + e.cost){
        come[e.to] = v;
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}
int ham(string s1, string s2) {
  int ret = 0;
  FOR(i,0,s1.length()) {
    if(s1[i] != s2[i]) ret++;
  }
  return ret;
}
int main()
{

  string s, g;
  cin >> s >> g;
  MAP[s] = 0;
  MAP[g] = 2000;
  PAM[0] = s;
  PAM[2000] = g;
  vector<string> vs;
  vs.push_back(s);
  vs.push_back(g);
  int num = 1;
  int n; cin >> n;
  FOR(i,0,n) {
    string in;
    cin >> in;
    if(MAP.count(in)==0) {
      MAP[in] = num;
      PAM[num] = in;
      num++;
      vs.push_back(in);
    }
  }

  // 最初から同じとき
  if(s == g) {
    cout << 0 << endl;
    cout << s << endl;
    cout << g << endl;
    return 0;
  }

  // ハミング距離計算
  N = vs.size(); // 頂点数
  FOR(i, 0, N) {
    FOR(j, 0, N) {
      if(ham(vs[i], vs[j]) == 1) {
        G[MAP[vs[i]]].push_back(edge(MAP[vs[j]], 1));
      }
    }
  }
  dijkstra(0);
  if(d[2000] == inf) {
    cout << -1 << endl;
    return 0;
  }
  cout << d[2000] - 1 << endl;
  vector<int> ans;
  int now = 2000;
  ans.push_back(2000);
  while(now!=0) {
    now = come[now];
    ans.push_back(now);
  }
  for(int i = ans.size() - 1; i >= 0; i--) {
    cout << PAM[ans[i]] << endl;
  }
  return 0;
}
