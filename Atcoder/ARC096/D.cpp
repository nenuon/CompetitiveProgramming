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
//右回りか、左回りか
ll dp_r[100005],dp_l[100005];
ll dp_rb[100005],dp_lb[100005];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N,C;cin>>N>>C;
  ll x1[N],x2[N],v1[N],v2[N];
  FOR(i,0,N)cin>>x1[i]>>v1[i];
  FOR(i,0,N)x2[i]=C-x1[N-i-1];
  FOR(i,0,N)v2[i]=v1[N-i-1];
  ll ans=0;
  ll now=0;
  FOR(i,0,N){
    now+=v1[i];
    dp_l[i+1]=max(dp_l[i],now-x1[i]);
    dp_lb[i+1]=max(dp_lb[i],now-2*x1[i]);
  }
  now=0;
  FOR(i,0,N){
    now+=v2[i];
    dp_r[i+1]=max(dp_r[i],now-x2[i]);
    dp_rb[i+1]=max(dp_rb[i],now-2*x2[i]);
  }
  FOR(i,0,N+1){
    ans=max(ans,max(dp_l[i],dp_r[N-i]));
    ans=max(ans,dp_lb[i]+dp_r[N-i]);
    ans=max(ans,dp_l[i]+dp_rb[N-i]);
  }
  cout<<ans<<endl;
}