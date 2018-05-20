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
typedef pair<int, int> P;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h,w;cin>>h>>w;
  int cost[h][w];
  FOR(i,0,h)FOR(j,0,w)cost[i][j]=1e9;
  vector<string> vs(h);
  int sy,sx,gy,gx;
  FOR(i,0,h){
    cin>>vs[i];
    FOR(j,0,w){
      if(vs[i][j]=='s'){
        sy=i;
        sx=j;
      }
      if(vs[i][j]=='g'){
        gy=i;
        gx=j;
      }
    }
  }
  deque<P> deq;
  deq.push_front(P(sy,sx));
  cost[sy][sx]=0;
  while(!deq.empty()){
    int y=deq.front().first;
    int x=deq.front().second;
    deq.pop_front();
    //if(cost[ny][nx]!=1e9)continue;
    FOR(i,0,4){
      int ny=y+dy[i];
      int nx=x+dx[i];
      if(ny<0||ny>=h||nx<0||nx>=w)continue;
      int nc=cost[y][x]+(vs[ny][nx]=='#');
      if(cost[ny][nx]<=nc)continue;
      cost[ny][nx]=nc;
      if(vs[ny][nx]=='#'){
        deq.push_back(P(ny,nx));
      }else{
        deq.push_front(P(ny,nx));
      }
    }
  }
  cout<<(cost[gy][gx]<=2?"YES":"NO")<<endl;
  return 0;
}