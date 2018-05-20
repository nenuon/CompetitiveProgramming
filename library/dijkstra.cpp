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
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
struct Dijkstra {
  typedef pair<int, int> P;
  struct edge {
    int to;
    int cost;
  };
  int V;
  vector<vector<edge> > G;
  vector<int> d;
  Dijkstra (int V):V(V) {
    G.resize(V+1);
    d.resize(V+1,1e9);
  }
  void calc(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    d[s]=0;
    que.push(P(0, s));
    while(!que.empty()){
      P p=que.top();que.pop();
      if(d[p.second]<p.first)continue;
      for(auto v : G[p.second]){
        if(d[v.to]>d[p.second]+v.cost){
          d[v.to]=d[p.second]+v.cost;
          que.push(P(d[v.to],v.to));
        }
      }
    }
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N,M,T;
  cin>>N>>M>>T;
  Dijkstra D1(N);
  Dijkstra D2(N);
  int A[N];
  FOR(i,0,N)cin>>A[i];
  FOR(i,0,M){
    int a,b,c;
    cin>>a>>b>>c;
    D1.G[a].push_back({b,c});
    D2.G[b].push_back({a,c});
  }
  D1.calc(1);
  D2.calc(1);
  ll ans=0;
  FOR(i,1,N+1){
    //cout<<D1.d[i]<<endl;
    if(D1.d[i]==1e9||D2.d[i]==1e9)continue;
    ans=max(ans,(ll)(T-D1.d[i]-D2.d[i])*A[i-1]);
  }
  cout<<ans<<endl;
}