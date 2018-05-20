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
// 連続してるやつ-1 * グループ数
int main()
{
  int N; cin >> N;
  int ans = 0;
  int cnt = 0;
  FOR(i,1,N+1) {
    int in; cin >> in;
    if(in == i) cnt++;
    else {
      if(cnt == 1) ans++;
      else if(cnt % 2 == 0) ans += cnt / 2;
      else if(cnt % 2 == 1) ans += cnt / 2 + 1;
      cnt = 0;
    }
  }
  if(cnt == 1) ans++;
  else if(cnt % 2 == 0) ans += cnt / 2;
  else if(cnt % 2 == 1) ans += cnt / 2 + 1;
  cout << ans << endl;
  return 0;
}
