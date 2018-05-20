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
  ll A,B,K,L;
  cin >> A >> B >> K >> L;
  ll ans = (K + L - 1) / L * B; // 全てセット
  ans = min(ans, K / L * B + K % L * A);
  cout << ans << endl;
  return 0;
}
