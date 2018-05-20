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
const ll MOD = 1000000007;
const int SIZE = 1010;
ll inv[SIZE],fac[SIZE],finv[SIZE];
void make(){
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i = 2; i < SIZE; i++){
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
ll C (int a,int b) {
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
// bの逆元求める
ll IE(ll b) {
  ll ret = 1;
  ll M = MOD - 2;
  for (; M; b = (b * b) % MOD, M >>= 1) {
    if(M & 1) ret = (ret * b) % MOD;
  }
  return ret % MOD;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, K; cin >> N >> K;
  make();
  ll x = K % N;
  ll ans = 0;
  if(K >= N) ans = C(N, x);
  else {
    ans = 1;
    FOR(i,1,K+N) {
      ans *= i;
      ans %= MOD;
    }
    FOR(i,1,K+1) {
      ans *= IE(i);
      ans %= MOD;
    }
    FOR(i,1,N) {
      ans *= IE(i);
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}