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
  string s, t; cin >> s >> t;
  vector<string> ans;
  int x = -1;
  FOR(i,0,s.length()) {
    bool ok = true;
    FOR(j,0,t.length()) {
      if(s[i+j] == '?') continue;
      if(s[i+j] != t[j]) ok = false;
    }
    if(ok) {
      x = i;
      string ss = "";
      FOR(i,0,x) {
        if(s[i] == '?') ss += "a";
        else ss+= s[i];
      }
      ss += t;
      FOR(i,x+t.length(),s.length()) {
        if(s[i] == '?') ss += "a";
        else ss += s[i];
      }
      ans.push_back(ss);
    }
  }
  if(x < 0) cout << "UNRESTORABLE" << endl;
  else {
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
  }
  return 0;
}