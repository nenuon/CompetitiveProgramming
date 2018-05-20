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
  int num[26]; CLR(num);
  FOR(i,0,s.length()) num[s[i]-'a']++;
  FOR(i,0,26) {
    if(num[i] > 1) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0;
}
