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
const int SIZE = 1000;
const ll MOD = 1000000007;
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
ll calcC (int a,int b) {
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}

int main()
{
  int R,C,X,Y,D,L;
  cin>>R>>C>>X>>Y>>D>>L;
  make();
  ll ans = (calcC(X*Y, D)%MOD)*((R-X+1)%MOD)*((C-Y+1)%MOD)%MOD;
  cout << ans << endl;
  return 0;
}
