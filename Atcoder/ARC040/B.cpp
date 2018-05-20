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
// 塗られていたら右へそうでないなら塗る
// 今いるところを塗って終わるなら終わらせる
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, R; cin >> N >> R;
  string s; cin >> s;
  int end = 0; // endで塗れば終わる
  for(int i = N - 1; i >= 0; i--) {
    if(s[i] == '.') {
      end = max(end, i - R + 1);
      break;
    }
    if(i == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  int j = 0, ans = 0;
  while(j < end) {
    if(s[j] == 'o') {
      ans++;
      j++;
    } else {
      ans++;
      FOR(i,0,R) s[i+j] = 'o';
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
