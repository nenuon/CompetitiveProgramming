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
  bool F[N][10]; CLR(F);
  FOR(i,0,N) FOR(j,0,10) cin >> F[i][j];
  int P[N][10];
  FOR(i,0,N) FOR(j,0,11) cin >> P[i][j];
  int ans = -1e9;
  FOR(i,0,1<<10) {
    bool open[10]; CLR(open);
    bool ok = false;
    FOR(j,0,10) {
      if((i>>j)&1) {
        open[j] = true;
        ok = true;
      }
    }
    if(!ok) continue;
    int cnt[N]; CLR(cnt);
    FOR(j,0,N) {
      FOR(k,0,10) {
        if(F[j][k] && open[k]) cnt[j]++;
      }
    }
    int p = 0;
    FOR(j,0,N) p += P[j][cnt[j]];
    ans = max(ans, p);
  }
  cout << ans << endl;
  return 0;
}