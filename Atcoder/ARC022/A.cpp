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
  int cnt = 0;
  FOR(i,0,s.length()) {
    s[i] = toupper(s[i]);
    if(cnt == 0 && s[i] == 'I') cnt++;
    else if(cnt == 1 && s[i] == 'C') cnt++;
    else if(cnt == 2 && s[i] == 'T') cnt++;
  }
  puts(cnt==3?"YES":"NO");
  return 0;
}
