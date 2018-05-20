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

int main()
{
  int N;
  cin >> N;
  set<int> SET;
  bool dp[101][301];
  FOR(i,0,101) FOR(j,0,301) dp[i][j] = false;
  dp[0][0] = true;
  FOR(i,0,3) {
    int ng;
    cin >> ng;
    SET.insert(ng);
  }
  FOR(i,0,100) {
    FOR(j,0,301) {
      if(!dp[i][j]) continue;
      FOR(k,0,4) {
        if(j+k>300 || SET.count(j+k)) continue;
        dp[i+1][j+k] = dp[i][j]; // true
      }
    }
  }
  puts(dp[100][N]?"YES":"NO");
  return 0;
}
