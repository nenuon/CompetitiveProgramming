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
  int N, A, B; cin >> N >> A >> B;
  int now = 0;// East +
  FOR(i,0,N) {
    string s; cin >> s;
    int d; cin >> d;
    if(s[0] == 'E') now += min(B, max(A, d));
    else now -= min(B, max(A, d));
  }
  if(now == 0) cout << 0 << endl;
  else if(now > 0) cout << "East " << now << endl;
  else cout << "West " << abs(now) << endl;
  return 0;
}
