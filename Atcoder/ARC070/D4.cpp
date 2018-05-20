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
// aiが不必要ならajも不必要
bool dp[5050][5050];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N,K;
  cin>>N>>K;
  int a[N];
  FOR(i,0,N)cin>>a[i];
  sort(a,a+N);
  // iが必要かどうか
  int l=-1,r=N;
  while(r-l>1){
    int med = (l + r) / 2;
    vector<int> b;
    FOR(j,0,N){
      if(med==j)continue;
      b.push_back(a[j]);
    }
    CLR(dp);
    dp[0][0]=true;
    FOR(i,0,N-1){
      FOR(j,0,K+1){
        // 加える
        if(j+b[i]<=K)
        dp[i+1][j+b[i]] |= dp[i][j];
        // 加えない
        dp[i+1][j] |= dp[i][j];
      }
    }
    bool need = false;
    FOR(j,max(0,K-a[med]),K){
      if(dp[N-1][j]){
        need = true;
        break;
      }
    }
    if(need){
      r = med;
    } else {
      l = med;
    }
  }
  cout<<r<<endl;
}