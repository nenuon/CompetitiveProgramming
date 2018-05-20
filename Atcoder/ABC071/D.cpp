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
const int mod = 1000000007;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll ans = 0;
  int N; cin >> N;
  string s1, s2; cin >> s1 >> s2;
  bool tate = false;
  int j = 0;
  if(s1[0] == s2[0]) {
    tate = true;
    ans = 3;
    j = 1;
  } else {
    tate = false;
    ans = 6;
    j = 2;
  }
  while(j < N) {
    if(s1[j] == s2[j]) {
      // 縦->縦
      if(tate) {
        ans *= 2;
      } else {
        ans *= 1;
      }
      j++;
      tate = true;
    } else {
      // 縦->横
      if(tate) {
        ans *= 2;
      } else {
        ans *= 3;
      }
      j += 2;
      tate = false;
    }
    ans %= mod;
  }
  cout << ans << '\n';
  return 0;
}
