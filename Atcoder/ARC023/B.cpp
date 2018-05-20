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
  int H, W, D; cin >> H >> W >> D;
  int A[H][W]; FOR(i,0,H) FOR(j,0,W) cin >> A[i][j];
  int ans = 0;
  FOR(i,0,H) {
    FOR(j,0,W) {
      if(i + j > D) continue;
      if((D - i - j) % 2 == 0) ans = max(ans, A[i][j]);
      //cout << "y" << i << "x" << j << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
