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
  int n; cin >> n;
  vector<string> vs(n);
  FOR(i,0,n) cin >> vs[i];
  int ans = 0;
  FOR(i,0,9) {
    bool o = false;
    FOR(j,0,n) {
      if(vs[j][i] == 'o') {
        if(!o) {
          o = true;
          ans++;
        }
      } else if(vs[j][i] == 'x') {
        o = false;
        ans++;
      } else o = false;
    }
  }
  cout << ans << endl;
  return 0;
}
