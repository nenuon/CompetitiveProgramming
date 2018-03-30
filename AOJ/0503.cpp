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
const int MAX=15000000;
int cost[MAX];
int three[15];
int n,m;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  three[0]=1;
  FOR(i,1,15)three[i]=three[i-1]*3;
  while(cin>>n>>m,n||m){
    int mask=0;
    FOR(i,0,3){
    int x;cin>>x;
    FOR(j,0,x){
      int a;cin>>a;
      a--;
      mask+=i*three[a];
    }
  }
  int all=0;
  FOR(i,0,n)all+=2*three[i];
  FOR(i,0,all+1)cost[i]=2e9;
  cost[mask]=0;
  //cout<<mask<<endl;
  queue<int> que;
  que.push(mask);
  bool next=false;
  while(!que.empty()){
    int now=que.front();que.pop();
    int mx[3];
    FOR(i,0,3)mx[i]=-1;
    int nownow=now;
    FOR(i,0,n){
      mx[nownow%3]=i;
      nownow/=3;
    }
    //cout<<now<<" "<<mx[0]<<" "<<mx[1]<< " "<<mx[2]<<endl;
    if(now==0||now==all){
      if(cost[now]<=m)cout<<cost[now]<<endl;
      else cout<<-1<<endl;
      next=true;
      break;
    }
    //0->1
    if(mx[0]>mx[1]){
      int mask2=now-0*three[mx[0]]+1*three[mx[0]];
      if(cost[mask2]>cost[now]+1){
        cost[mask2]=cost[now]+1;
        que.push(mask2);
      }
    }
    //1->0
    if(mx[1]>mx[0]){
      int mask2=now-1*three[mx[1]]+0*three[mx[1]];
      if(cost[mask2]>cost[now]+1){
        cost[mask2]=cost[now]+1;
        que.push(mask2);
      }
    }
    //1->2
    if(mx[1]>mx[2]){
      int mask2=now-1*three[mx[1]]+2*three[mx[1]];
      if(cost[mask2]>cost[now]+1){
        cost[mask2]=cost[now]+1;
        que.push(mask2);
      }
    }
    //2->1
    if(mx[2]>mx[1]){
      int mask2=now-2*three[mx[2]]+1*three[mx[2]];
      if(cost[mask2]>cost[now]+1){
        cost[mask2]=cost[now]+1;
        que.push(mask2);
      }
    }
  }
  if(!next)cout<<-1<<endl;
  }
  return 0;
}
