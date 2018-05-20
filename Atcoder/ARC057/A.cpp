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

int main(){
  ll A, K;
  cin >> A >> K;
  ll ans = 0;
  if (K == 0) {
    ans = 2 * 1000000000000 - A;
    cout <<  ans << endl;
    return 0;
  }
  while (A < 2e12) {
    A += 1 + K * A;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
