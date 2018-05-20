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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int E[6], B, L[6];
  FOR(i,0,6) cin >> E[i];
  cin >> B;
  FOR(i,0,6) cin >> L[i];
  bool b = false;
  int cnt = 0;
  FOR(i,0,6) {
    FOR(j,0,6) {
      if(E[i] == L[j]) cnt++;
    }
    if(L[i] == B) b = true;
  }
  if(cnt == 6) cout << 1 << '\n';
  else if(cnt == 5 && b) cout << 2 << '\n';
  else if(cnt == 5) cout << 3 << '\n';
  else if(cnt == 4) cout << 4 << '\n';
  else if(cnt == 3) cout << 5 << '\n';
  else cout << 0 << '\n';
  return 0;
}
