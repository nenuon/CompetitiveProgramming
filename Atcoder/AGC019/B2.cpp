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
  string A; cin >> A;
  ll len = A.length();
  ll cnt[26]; CLR(cnt);
  FOR(i,0,len) cnt[A[i]-'a']++;
  ll ans = len * (len - 1) / 2;
  FOR(i,0,26) {
    if(cnt[i] >= 2) {
      ans -= cnt[i] * (cnt[i] - 1) / 2;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}