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
  string s; cin >> s;
  int n = s.length();
  int ans = 1e9;
  FOR(i,0,1<<n) {
    vector<int> tv(n, 0);
    int cnt = 0;
    FOR(j,0,n) {
      if((i>>j)&1) {
        cnt++;
        FOR(k,0,n) {
          int l = j + k;
          l %= n;
          if(s[k] == 'o') tv[l] = 1;
        }
      }
    }
    bool ok = true;
    FOR(i,0,n) ok &= tv[i];
    if(ok) ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
