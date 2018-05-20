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
  int len = s.length();
  int diff = 0;
  FOR(i,0,len/2) {
    if(s[i] != s[len-1-i]) diff++;
  }
  int ans = 0;
  if(diff == 0) {
    if(len % 2 == 0) ans = 25 * len;
    else ans = 25 * (len - 1);
  }
  else if(diff == 1) ans = 25 * len - 2;
  else ans = 25 * len;
  cout << ans << endl;
  return 0;
}
