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
  int ans = 1;
  int mx = 0;
  FOR(i,1,N+1) {
    int cnt = 0;
    int n = i;
    while(n > 0) {
      if(n % 2 == 1) break;
      n /= 2;
      cnt++;
    }
    if(cnt > mx) {
      ans = i;
      mx = cnt;
    }
  }
  cout << ans << endl;
  return 0;
}
