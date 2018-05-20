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
  int X, Y; cin >> X >> Y;
  if(X < Y) cout << X << endl;
  else if(X == Y) cout << -1 << endl;
  else {
    if(X % Y == 0) cout << -1 << endl;
    else cout << X << endl;
  }
  return 0;
}