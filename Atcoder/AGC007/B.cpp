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
  int N; cin >> N;
  ll a[N], b[N];
  FOR(i,0,N) {
    a[i] = (i + 1) * 30000;
    b[i] = 1000000000 - a[i];
  }
  FOR(i,0,N) {
    ll p; cin >> p;
    p--;
    a[p] -= N - i;
  }
  FOR(i,0,N) printf("%lld%c",a[i],i==N-1?'\n':' ');
  FOR(i,0,N) printf("%lld%c",b[i],i==N-1?'\n':' ');
  return 0;
}
