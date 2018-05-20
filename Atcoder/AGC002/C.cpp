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
// 最後に一番長い組みを残せば良い
int main()
{
  ll N, L; cin >> N >> L;
  ll a[N]; FOR(i,0,N) cin >> a[i];
  ll mx = 0, nocut = 0;
  FOR(i,0,N-1) {
    if(a[i]+a[i+1]>mx) {
      nocut = i + 1;
      mx = a[i] + a[i+1];
    }
  }
  if(mx >= L) {
    puts("Possible");
    FOR(i,1,N) {
      if(i != nocut) cout << i << endl;
      else break;
    }
    for(int i = N - 1; i >= 1; i--) {
      if(i != nocut) cout << i << endl;
      else break;
    }
    cout << nocut << endl;
  } else {
    puts("Impossible");
  }
  return 0;
}