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
ll kika[1000006];
struct Combinatorics {
  using int64 = long long;
  int64 mod;
  int64 fact[1000006];
  int64 invfact[1000006];
  Combinatorics(int64 mod):mod(mod) {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < 1000006; ++i) {
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
// ちょうどk回目で全て黒くなる通り数を求めるのは難しい
// k回以下で黒くなっている通り数は求めやすい
// k個になる個数=(k以下の個数-(k-1)以下の個数)テク
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;cin>>N;
  if(N==2){
    cout<<1<<endl;
    return 0;
  }
  Combinatorics COM(mod);
  kika[N-1]=COM.mfact(N-1);
  for(int k=N-2;k>=(N-1)/2;k--){
    kika[k]=(COM.mfact(k)*COM.mfact(N-1-k))%mod;
    kika[k]=(kika[k]*COM.C(k-1,N-k-1))%mod;
  }
  ll ans=0;
  for(int k=N-1;k>=(N-1)/2;k--){
    ans=ans+((kika[k]-kika[k-1]+mod)%mod)*k%mod;
    ans%=mod;
  }
  cout<<ans<<endl;
}