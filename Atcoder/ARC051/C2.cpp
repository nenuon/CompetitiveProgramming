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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
const int mod = 1e9 + 7;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, A, B; cin >> N >> A >> B;
  ll a[N]; FOR(i,0,N) cin >> a[i];
  sort(a, a + N);
  if(A == 1) {
    FOR(i,0,N) cout << a[i] % mod << endl;
    return 0;
  }
  ll k = 0;
  // 周期的になるには何回A倍すれば良いか
  while(B) {
    sort(a, a + N);
    if(a[0] * A >= a[N-1]) break;
    a[0] *= A;
    B--;
  }
  sort(a, a + N);
  // 周期的になる前に終わる
  if(B == 0) FOR(i,0,N) cout << a[i] % mod << endl;
  // 周期的になる
  else {
    FOR(i,0,N) a[i] %= mod;
    // nokori / N 回 A倍する
    FOR(i,B%N,N) {
      ll C = B / N;
      ll AA = A % mod;
      while(C) {
        if(C&1) a[i] = (a[i] * AA) % mod;
        AA = (AA * AA) % mod;
        C >>= 1;
      }
    }
    FOR(i,0,B%N) {
      ll C = B / N + 1;
      ll AA = A % mod;
      while(C) {
        if(C&1) a[i] = (a[i] * AA) % mod;
        AA = (AA * AA) % mod;
        C >>= 1;
      }
    }
    FOR(i,0,N) {
      cout << a[(i+B%N)%N] << endl;
    }
  }
  return 0;
}