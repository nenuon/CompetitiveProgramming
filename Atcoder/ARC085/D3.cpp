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
  int N, Z, W; cin >> N >> Z >> W;
  int a[N]; FOR(i,0,N) cin >> a[i];
  int ans = 0;
  if(N == 1) ans = abs(W - a[0]);
  else ans = max(abs(a[N-1] - a[N-2]), abs(W - a[N-1]));
  cout << ans << endl;
  return 0;
}