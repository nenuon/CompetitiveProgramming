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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  ll A[N]; FOR(i,0,N) cin >> A[i];
  sort(A, A + N);
  reverse(A, A + N);
  ll j = 0, cnt = 0, ans = 1;
  while(j < N - 1) {
    if(A[j] == A[j+1]) {
      cnt += 2;
      ans *= A[j];
      j += 2;
      if(cnt == 4) {
        cout << ans << '\n';
        return 0;
      }
    } else {
      j++;
    }
  }
  cout << 0 << '\n';
  return 0;
}
