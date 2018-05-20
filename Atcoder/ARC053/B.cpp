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
  int e[26]; CLR(e);
  FOR(i,0,(int)s.length()) e[s[i]-'a']++;
  int N = 0, even = 0;
  FOR(i,0,26) {
    if(e[i] % 2 == 1) N++;
    even += e[i] / 2;
  }
  int ans = 0;
  if(N == 0) N = 1;
  else ans++;
  ans += even / N * 2;
  cout << ans << endl;
  return 0;
}
