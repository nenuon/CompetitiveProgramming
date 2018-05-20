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
  string s; cin >> s;
  map<char, char> MAP;
  MAP['O'] = '0';
  MAP['D'] = '0';
  MAP['I'] = '1';
  MAP['Z'] = '2';
  MAP['S'] = '5';
  MAP['B'] = '8';
  FOR(i,0,s.length()) {
    if(!isdigit(s[i])) {
      s[i] = MAP[s[i]];
    }
  }
  cout << s << endl;
  return 0;
}
