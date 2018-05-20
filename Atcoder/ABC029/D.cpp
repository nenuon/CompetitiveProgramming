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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
ll dp[11][2][11];
int main()
{
  string s;
  cin>>s;
  int len = s.length();
  FOR(i,0,len) FOR(j,0,2) FOR(k,0,11) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  FOR(i,0,len) FOR(j,0,2) FOR(k,0,11){
    int lim = j ? 9 : s[i] - '0';
    FOR(d,0,lim+1) {
      dp[i+1][j||d<lim][k+(d==1)] += dp[i][j][k];
    }
  }
  ll ans = 0;
  FOR(j,0,2) FOR(k,1,len+1) {
    ans += dp[len][j][k] * k;
  }
  cout << ans << endl;
  return 0;
}
