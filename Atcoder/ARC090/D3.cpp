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
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
struct edge{
  int to, cost;
  edge(int t, int c) {
    to = t, cost = c;
  }
};
int N,M;
vector<edge> G[100005];
int D[100005];
bool dfs(int v){
  bool ret=true;
  for(auto to : G[v]){
    if(D[to.to]==2e9){
      D[to.to]=D[v]+to.cost;
      if(!dfs(to.to))return false;
    }else{
      ret&=(D[to.to]==D[v]+to.cost);
    }
  }
  return ret;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>N>>M;
  FOR(i,0,M){
    int l,r,d;
    cin>>l>>r>>d;
    G[l].push_back(edge(r,d));
    G[r].push_back(edge(l,-d));
  }
  FOR(i,0,N+1)D[i]=2e9;
  FOR(i,1,N+1){
    if(D[i]==2e9){
      D[i]=0;
      if(!dfs(i)){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}