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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  FOR(i,1,s.length()) {
    int len = s.length() - i;
    if(len % 2 == 1) continue;
    bool ok = true;
    FOR(j,0,len/2) {
      if(s[j] != s[j+len/2]) {
        ok = false;
        break;
      }
    }
    if(ok) {
      cout << len << endl;
      return 0;
    }
  }
  return 0;
}
