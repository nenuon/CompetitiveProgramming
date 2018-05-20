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
typedef pair<int, int> P;
int main()
{
  int N; cin >> N;
  set<P> SET;
  FOR(i,0,N) {
    int m, d; scanf("%d/%d", &m, &d);
    SET.insert(P(m, d));
  }
  int hurikae = 0;
  int m = 1, d = 1;
  int youbi = 0; // 日月火...
  int cnt = 0, ans = 0;
  while(m != 13 ||  d != 1) {
    // 祝日
    if(SET.count(P(m, d))) {
      if(youbi == 0 || youbi == 6) {
        hurikae++;
      }
      cnt++;
    }
    // 祝日じゃない土日
    else if(youbi == 0 || youbi == 6) {
      cnt++;
    }
    // 平日
    else {
      if(hurikae) {
        hurikae--;
        cnt++;
      } else {
        ans = max(ans, cnt);
        cnt = 0;
      }
    }
    d++;
    youbi++;
    youbi %= 7;
    if(m == 2 && d == 30) {
      m++;
      d = 1;
    } else if((m == 4 || m == 6 || m == 9 || m == 11) && d == 31) {
      m++;
      d = 1;
    } else if((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d == 32) {
      m++;
      d = 1;
    }
  }
  ans = max(ans, cnt);
  cout << ans << endl;
  return 0;
}
