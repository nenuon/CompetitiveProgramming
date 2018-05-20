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

// 行列累乗
typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat &a, mat &b) {
  mat ret(a.size(), vec(b[0].size(), 0));
  FOR(i,0,a.size()) {
    FOR(j,0,b[0].size()) {
      FOR(k,0,b.size()) {
        ret[i][j] ^= a[i][k] & b[k][j];
      }
    }
  }
  return ret;
}
mat fastpow(mat &a, ll n) {
  mat ret(a.size(), vec(a.size()));
  FOR(i,0,a.size()) FOR(j,0,a.size()) ret[i][i] = (1LL<<60)-1; // ANDに対する1は2^n-1->1111111111111ってやつ
  while(n) {
    if(n & 1) ret = mul(ret, a);
    a = mul(a, a);
    n >>= 1;
  }
  return ret;
}

int main()
{
  ll K, M;
  cin >> K >> M;
  mat A(K, vec(1)); // K*1の行列として表現
  mat C(K, vec(K));
  FOR(i,0,K) cin >> A[K-1-i][0];
  FOR(i,0,K) cin >> C[0][i];
  FOR(i,0,K-1) C[i+1][i] = (1LL<<60)-1; // ANDに対する1は2^n-1->1111111111111ってやつ
  mat CC = fastpow(C,M-1);
  mat ans = mul(CC, A);
  cout << ans[K-1][0] << endl;
  return 0;
}
