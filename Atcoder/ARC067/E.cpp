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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
const int mod = 1000000007;

ll inv[1010],fac[1010],finv[1010];
void make(){
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<1010;i++){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		fac[i]=fac[i-1]*(ll) i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
ll nCr (int a,int b) {
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%mod)%mod;
}

ll dp[1010][1010];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  make();
  int N,A,B,C,D;
  cin>>N>>A>>B>>C>>D;
  FOR(i,0,1010) dp[i][0] = 1;
  FOR(i,A,B+1) {
    FOR(j,0,N+1) {
      if(dp[i][j] == 0) continue;
      if(j != 0)(dp[i+1][j] += dp[i][j]) %= mod;
      ll p = 1;
      for(int k = 1; k <= D && j + k * i <= N; k++) {
        p = p * nCr(N - j - i * (k - 1), i) % mod * inv[k] % mod;
        (dp[i+1][j+k*i] += dp[i][j] * p % mod) %= mod;
      }
    }
  }
  cout << dp[B+1][N] << endl;
  return 0;
}