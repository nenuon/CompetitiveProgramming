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
  int H, W; cin >> H >> W;
  vector<vector<string> > vs(H, vector<string>(W));
  FOR(i,0,H) {
    FOR(j,0,W) {
      cin >> vs[i][j];
    }
  }
  FOR(y,0,H) {
    FOR(x,0,W) {
      if(vs[y][x] == "snuke") {
        char c = 'A' + x;
        cout << c << y + 1 << endl;
        return 0;
      }
    }
  }
  return 0;
}
