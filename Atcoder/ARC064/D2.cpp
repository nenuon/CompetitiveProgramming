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
  if(s[0] == s[s.length()-1]) {
    if(s.length() % 2 == 1) puts("Second");
    else puts("First");
  } else {
    if(s.length() % 2 == 0) puts("Second");
    else puts("First");
  }
  return 0;
}