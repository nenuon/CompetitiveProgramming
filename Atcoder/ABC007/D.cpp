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

ll dp[30][2][2]; // 調べた桁数、小さいことが確定しているか、4or9があるか

ll calc(string s) {
  int len = s.length();
  FOR(i,0,len+1) FOR(j,0,2) FOR(k,0,2) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  FOR(i,0,len) FOR(j,0,2) FOR(k,0,2) {
    int lim = j ? 9 : s[i] - '0';
    FOR(d,0,lim+1) {
      dp[i+1][j||d<lim][k||d==4||d==9] += dp[i][j][k];
    }
  }
  ll ret = 0;
  FOR(j,0,2) {
    ret += dp[len][j][1];
  }
  return ret - 1; // 0もカウントされるので-1
}

int main()
{
  ll A, B;
  cin>>A>>B;
  cout << calc(to_string(B)) - calc(to_string(A-1)) << endl;
  return 0;
}
