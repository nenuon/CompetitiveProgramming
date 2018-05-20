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
  ll n = s.length();
  ll cnt[26]; CLR(cnt);
  FOR(i,0,n) {
    cnt[s[i]-'a']++;
  }
  ll mx = n * (n - 1) / 2;
  FOR(i,0,26) {
    mx -= cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << mx + 1 << endl;
  return 0;
}