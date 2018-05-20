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
const int mod = 1000000007;
// 部分点
// 答え見た
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> D(N); FOR(i,0,N) cin >> D[i];
  sort(D.begin(), D.end());
  int A[N], B[N]; CLR(A); CLR(B);
  FOR(i,0,N) {
    A[i] = N - (lower_bound(D.begin(), D.end(), 2*D[i]) - D.begin());
    B[i] = upper_bound(D.begin(), D.end(), D[i]/2) - D.begin();
  }
  ll sumA[N+1]; CLR(sumA);
  FOR(i,0,N) sumA[i+1] += sumA[i] + A[i];
  ll ans = 0;
  FOR(i,1,N-1) {
    ll sum = B[i];
    sum = (sum * (sumA[N] - sumA[N-A[i]])) % mod;
    ans = (ans + sum) % mod;
  }
  cout << ans << endl;
  return 0;
}