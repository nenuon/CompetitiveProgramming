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
const int mod=1e9+7;
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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll R,C,X,Y,D,L;
  cin>>R>>C>>X>>Y>>D>>L;
  Combinatorics c1(mod);
  ll ans=0;
  FOR(i,0,1<<4){
    ll x=X,y=Y;
    int cnt=0;
    FOR(j,0,4){
      if(i&(1<<j)){
        cnt++;
        if(j==0||j==1){
          y--;
        }else{
          x--;
        }
      }
    }
    x=max(x,0LL);
    y=max(y,0LL);
    if(cnt&1){
      ans=ans-(c1.C(x*y,D)*c1.C(x*y-D,L))%mod+mod;
    }else{
      ans=ans+(c1.C(x*y,D)*c1.C(x*y-D,L))%mod;
    }
    ans%=mod;
  }
  ans=(((ans*(R-X+1))%mod)*(C-Y+1))%mod;
  cout<<ans%mod<<endl;
  return 0;
}