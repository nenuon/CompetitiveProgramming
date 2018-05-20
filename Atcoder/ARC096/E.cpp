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
ll N,M;
const int MAX=3030;
ll dp[MAX+1][MAX+1];
struct Combinatorics {
  using int64 = long long;
  int64 mod;
  int64 fact[202020];
  int64 invfact[202020];
  Combinatorics(int64 mod):mod(mod) {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < 202020; ++i) {
      fact[i] = fact[i-1]*i%mod;
      invfact[i] = minv(fact[i]);
    }
  }
  int64 mpow(int64 x, int64 n) const {
    int64 res = 1;
    while(n > 0) {
      if(n&1) res = res*x%mod;
      x = x*x%mod;
      n >>= 1;
    }
    return res;
  }
  int64 minv(int64 x) const {
    return mpow(x, mod-2);
  }
  int64 mfact(int64 x) const {
    return fact[x];
  }
  int64 C(int64 n, int64 r) const {
    if(r < 0 || n < r) return 0;
    return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
  }
  int64 P(int64 n, int64 r) const {
    if(r < 0 || n < r) return 0;
    return fact[n]*invfact[n-r]%mod;
  }
};
void calcDP(){
  dp[0][0]=1;
  FOR(i,1,MAX){
    FOR(j,0,i+1){
      (dp[i][j]+=dp[i-1][j]*(j+1)%M)%=M;
      if(j)(dp[i][j]+=dp[i-1][j-1])%=M;
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>N>>M;
  calcDP();
  Combinatorics c1(M);
  Combinatorics c2(M-1);
  ll ans=0;
  FOR(k,0,N+1){
    ll cal=0;
    ll b=c1.mpow(2,N-k);
    ll p=1;
    FOR(x,0,k+1){
      cal=(cal+dp[k][x]*p)%M;
      p=p*b%M;
    }
    cal=(cal*c1.C(N,k))%M;
    cal=(cal*c1.mpow(2,c2.mpow(2,N-k)))%M;
    if(k&1){
      ans = (ans - cal + M) % M;
    }else{
      ans = (ans + cal) % M;
    }
  }
  cout<<ans<<endl;
  return 0;
}