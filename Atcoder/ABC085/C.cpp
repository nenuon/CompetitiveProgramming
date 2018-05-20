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
  int N, Y;
  cin >> N >> Y;
  FOR(x,0,N+1) {
    FOR(y,0,N+1) {
      if(x + y > N) continue;
      int z = N - x - y;
      int yen = 10000 * x + 5000 * y + 1000 * z;
      if(Y == yen) {
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}