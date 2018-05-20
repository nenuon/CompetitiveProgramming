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
  int a[N], b[N];
  FOR(i,0,N) cin >> a[i];
  FOR(i,0,N) cin >> b[i];
  int ans = 0;
  int cnt = a[0];
  FOR(i,0,N) cnt += b[i];
  ans = max(ans, cnt);
  FOR(i,1,N) {
    cnt += a[i];
    cnt -= b[i-1];
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;

}