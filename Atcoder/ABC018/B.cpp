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
  int N; cin >> N;
  FOR(i,0,N) {
    int l, r; cin >> l >> r;
    l--;r--;
    string bf = (l == 0 ? "" : s.substr(0, l));
    string af = (r == (int)s.length() - 1 ? "" : s.substr(r + 1, (int)s.length() - r));
    string cen = s.substr(l, r - l + 1);
    reverse(cen.begin(), cen.end());
    s = bf + cen + af;
  }
  cout << s << endl;
  return 0;
}
