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
#include <iomanip>
#include <limits>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int dp[500005];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  string s; cin >> s;
  int n = s.length();
  FOR(i,0,n) {
    if(i>0) dp[i] = max(dp[i], dp[i-1]);
    if(s[i] == '0') {
      int l = 1, r = 1;
      while(i-l>=0&&s[i-l]=='1') l++;
      while(i+r<n&&s[i+r]=='1') r++;
      // 両サイドが1
      if(l > 1 && r > 1) {
        l--;
        r--;
        // 右に行く(あげるdp)
        for(int j = i + 1; j <= i + r; j++) {
          dp[j] = max(dp[j], (i>1?dp[i-2]:0) + j - i);
        }
        // 左に行く(もらうdp)
        for(int j = i - l; j < i; j++) {
          dp[i+1] = max(dp[i+1], (j>0?dp[j-1]:0) + i - j);
        }
      }
    }
  }
  //FOR(i,0,n) cout << dp[i] << endl;
  cout << dp[n-1] << endl;
  return 0;
}
