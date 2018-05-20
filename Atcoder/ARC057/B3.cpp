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
// dp[i][j]:=i日目まででj回増加した時の最小の勝利数
// j<=K
ll dp[2020][2020];
ll a[2020],b[2020];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N,K;
  cin>>N>>K;
  ll sum=0;
  FOR(i,0,N){
    cin>>a[i];
    sum+=a[i];
    b[i+1]=b[i]+a[i];
  }
  b[0]=1;
  if(sum==K){
    cout<<1<<endl;
    return 0;
  }
  FOR(i,0,N+1)FOR(j,0,N+1)dp[i][j]=1e18;
  dp[0][0]=0;
  FOR(i,0,N){
    FOR(j,0,N+1){
      if(dp[i][j]==1e18)continue;
      // i->i+1で勝率を増加させないなら1勝もしない方が良い
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      // i->i+1で勝率が増加するなら最低限勝つのが良い
      ll x=dp[i][j]*a[i]/b[i]+1;
      if(x<=a[i])dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+x);
    }
  }
  int ans=1e18;
  FOR(j,0,N+1){
    if(dp[N][j]<=K)ans=j;
  }
  cout<<ans<<endl;
  return 0;
}