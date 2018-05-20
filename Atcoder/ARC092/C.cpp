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
int N;
vector<int> G[222];
int match[222];
bool used[222];
bool dfs(int v){
  used[v]=true;
  for(int i=0;i<G[v].size();i++){
    int u=G[v][i], w=match[u];
    if(w<0||(!used[w]&&dfs(w))){/////////
      match[v]=u;
      match[u]=v;
      return true;
    }
  }
  return false;
}
int solve(){
  int res = 0;
  memset(match,-1,sizeof(match));
  for(int v=0;v<2*N;v++){
    if(match[v]<0){
      memset(used,0,sizeof(used));
      if(dfs(v))res++;
    }
  }
  return res;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>N;
  int a[N],b[N],c[N],d[N];
  FOR(i,0,N)cin>>a[i]>>b[i];
  FOR(i,0,N)cin>>c[i]>>d[i];
  FOR(i,0,N){
    FOR(j,0,N){
      if(a[i]<c[j]&&b[i]<d[j]){
        G[i].push_back(j+100);
        G[j+100].push_back(i);
      }
    }
  }
  cout<<solve()<<endl;
}