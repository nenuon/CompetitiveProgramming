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
  int n;
  cin >> n;
  int dp[n+1];
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 0;
  dp[3] = 1;
  FOR(i, 4, n+1) {
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    dp[i] %= 10007;
  }
  cout << dp[n] % 10007 << endl;
  return 0;
}
