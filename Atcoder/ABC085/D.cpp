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
  int N, H; cin >> N >> H;
  vector<int> a(N), b(N);
  FOR(i,0,N) {
    cin >> a[i] >> b[i];
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  int p = 0;
  int ans = 0;
  int i = 0;
  while(p < H && i < N) {
    p += max(a[0], b[i]);
    i++;
    ans++;
  }
  if(p >= H) {
    cout << ans << endl;
  } else {
    cout << ans + (H - p + a[0] - 1) / a[0] << endl;
  }
  return 0;

}