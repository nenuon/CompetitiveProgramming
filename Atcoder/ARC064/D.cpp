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
  int len = s.length();
  // 最終的に奇数個で終わる
  if(s[0] == s[len-1]) {
    if(len % 2 == 0) {
      puts("First");
    } else {
      puts("Second");
    }
  }
  // 偶数個で終わる
  else {
    if(len % 2 == 1) {
      puts("First");
    } else {
      puts("Second");
    }
  }
  return 0;
}