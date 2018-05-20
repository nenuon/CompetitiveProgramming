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
typedef pair<int, int> P;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s; cin >> s;
  int len = s.length();
  int m = 0, p = 0;
  vector<P> r;
  for(int i = len - 1; i >= 0; i--) {
    if(s[i] == '+') p++;
    if(s[i] == '-') m++;
    if(s[i] == 'M') r.push_back(P(p - m, i));
  }
  sort(r.rbegin(), r.rend());
  bool mvr[len]; CLR(mvr);
  FOR(i,0,r.size()/2) mvr[r[i].second] = true;
  int x = 0;
  int ans = 0;
  FOR(i,0,len) {
    if(s[i] == 'M') x += mvr[i] ? 1 : -1;
    else if(s[i] == '+') ans += x;
    else ans -= x;
  }
  cout << ans << endl;
  return 0;
}