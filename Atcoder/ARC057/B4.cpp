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
ll dp[2020][2020];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N,K;
  cin>>N>>K;
  ll a[N];
  ll A[N+1];
  A[0]=0;
  ll sum=0;
  FOR(i,0,N){
    cin>>a[i];
    sum+=a[i];
    A[i+1]=A[i]+a[i];
  }
  A[0]=1; // 0除算を避けるため
  if(K==sum){
    cout<<1<<endl;
    return 0;
  }
  FOR(i,0,2020)FOR(j,0,2020)dp[i][j]=1e9;
  dp[0][0]=0;
  int ans=0;
  FOR(i,0,N){
    FOR(j,0,N+1){
      // 勝率が上がらないなら0勝が良い
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
      // ぎりぎり勝率をあげるのが良い
      ll x = dp[i][j]*A[i+1]/A[i]+1;
      dp[i+1][j+1] = min(dp[i+1][j+1], x);
    }
  }
  FOR(i,0,N+1){
    if(dp[N][i]<=K){
      ans=max(ans,i);
    }
  }
  cout<<ans<<endl;
}