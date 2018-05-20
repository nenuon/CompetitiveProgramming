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

int main()
{
  int N, T; cin >> N >> T;
  int A[N]; FOR(i,0,N) scanf("%d", A+i);
  ll ans = 0;
  int st = A[0];
  FOR(i,1,N) {
    if(A[i-1] + T < A[i]) {
      ans += (A[i-1] + T - st);
      st = A[i];
    }
  }
  ans += (A[N-1] + T - st);
  cout << ans << endl;
  return 0;
}
