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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

const ll MOD = 1000000007;
const int SIZE = 100;
ll inv[SIZE],fac[SIZE],finv[SIZE];
void make(){
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<SIZE;i++){
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
ll C (int a,int b) {
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
int main(){
  int N, P;
  cin>>N>>P;
  int A[N];
  make();
  FOR(i,0,N) cin >> A[i];
  int odd = 0, even = 0;
  FOR(i,0,N){
    if(A[i]%2==0) even++;
    else odd++;
  }
  ll ans = 0;
  if(P==0){
    ans = pow(2, even);
    int x = 0, times = 0;
    while(x <= odd){
      times += C(odd, x);
      x += 2;
    }
    ans *= times;
  } else {
    ans = pow(2, even);
    int x = 1, times = 0;
    while(x <= odd){
      times += C(odd, x);
      x += 2;
    }
    ans *= times;
  }
  cout << ans << endl;
  return 0;
}
