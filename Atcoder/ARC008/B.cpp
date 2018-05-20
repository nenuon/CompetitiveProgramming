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
  int N, M; cin >> N >> M;
  string name, kit; cin >> name >> kit;
  int alp_name[26], alp_kit[26];
  CLR(alp_name); CLR(alp_kit);
  FOR(i,0,N) alp_name[name[i]-'A']++;
  FOR(i,0,M) alp_kit[kit[i]-'A']++;
  int ans = 0;
  FOR(i,0,26) {
    if(alp_name[i] == 0 && alp_kit[i] == 0) continue;
    if(alp_name[i] > 0 && alp_kit[i] == 0) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, (alp_name[i]+alp_kit[i]-1)/alp_kit[i]);
  }
  cout << ans << endl;
  return 0;
}
