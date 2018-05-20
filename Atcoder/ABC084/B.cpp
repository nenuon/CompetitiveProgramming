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
  int a, b; cin >> a >> b;
  string s; cin >> s;
  if(s.length() != a + b + 1) cout << "No" << endl;
  else {
    FOR(i,0,s.length()) {
      if(i == a) {
        if(s[i] != '-') {
          cout << "No" << endl;
          return 0;
        }
      } else {
        if(!isdigit(s[i])) {
          cout << "No" << endl;
          return 0;
        }
      }
      
    }
  }
  cout << "Yes" << endl;
  return 0;
}
