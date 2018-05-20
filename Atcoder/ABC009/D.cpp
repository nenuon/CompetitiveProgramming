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
// 漸化式->行列累乗
typedef vector<vector<ll> > mat;

// 行列*行列
mat mul(mat &a, mat &b) {
  mat c(a.size(), vector<ll>(b[0].size()));
  FOR(i,0,a.size()) {
    FOR(j,0,b[0].size()) {
      FOR(k,0,b.size()) {
        c[i][j] ^= a[i][k] & b[k][j];
      }
    }
  }
  return c;
}

mat ppow(mat &a, ll n) {
  mat b(a.size(), vector<ll>(a.size()));
  FOR(i,0,a.size()) b[i][i] = (1LL << 60) - 1;
  while(n) {
    if (n & 1) b = mul(b, a); // n=100なら4(2^2),32(2^5),64(2^6)でbit1
    a = mul(a, a);
    n >>= 1;
  }
  return b;
}

int main()
{
  int k, m;
  cin >> k >> m;
  m--;
  mat A(k, vector<ll>(k)), C(k, vector<ll>(1));
  FOR(i,0,k) cin >> C[k-i-1][0];
  FOR(i,0,k) cin >> A[0][i];
  FOR(i,1,k) {
    A[i][i-1] = (1LL << 60) - 1;
    cout << (1LL << 60) - 1 << endl;
  }
  mat b = ppow(A, m);
  b = mul(b, C);
  cout << b[k-1][0] << endl;
  return 0;
}
