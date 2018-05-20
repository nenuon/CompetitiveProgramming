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
string s;
vector<int> v;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> s;
  int len = s.length();
  int l, r;
  if(len % 2 == 0) {
    l = len / 2 - 1;
    r = len / 2;
  } else {
    l = len / 2;
    r = len / 2;
  }
  int ans = len / 2;
  char c = s[l];
  while(l >= 0 && r < len && s[l] == c && s[r] == c) {
    l--;
    r++;
    ans++;
  }
  cout << ans << endl;
  return 0;
}