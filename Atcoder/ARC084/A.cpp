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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> A(N), B(N), C(N);
  FOR(i,0,N) cin >> A[i];
  FOR(i,0,N) cin >> B[i];
  FOR(i,0,N) cin >> C[i];
  ll ans = 0;
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  // 真ん中固定
  FOR(i,0,N) {
    ll tmp = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
    tmp *= N - (upper_bound(C.begin(), C.end(), B[i]) - C.begin());
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
}