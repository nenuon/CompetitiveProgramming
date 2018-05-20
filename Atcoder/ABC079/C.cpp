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
  FOR(i,0,1<<3) {
    string ans = "";
    ans += s[0];
    int num = s[0] - '0';
    FOR(j,0,3) {
      // +
      if((i>>j)&1) {
        num += s[j+1] - '0';
        ans += "+";
        ans += s[j+1];
      } else {
        num -= s[j+1] - '0';
        ans += "-";
        ans += s[j+1];
      }
    }
    if(num == 7) {
      ans += "=7";
      cout << ans << endl;
      return 0;
    }
  }
}