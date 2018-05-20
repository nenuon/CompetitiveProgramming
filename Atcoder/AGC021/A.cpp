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
  string s; cin >> s;
  ll ans = 0;
  FOR(i,0,s.length()) {
    ans += s[i]-'0';
  }
  FOR(i,0,s.length()) {
    if(s[i] == '0') continue;
    ll tmp = s[i] - '0' - 1;
    tmp += 9 * (s.length() - i - 1);
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}