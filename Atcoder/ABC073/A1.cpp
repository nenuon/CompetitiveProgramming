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
  int N; cin >> N;
  map<ll, int> MAP;
  FOR(i,0,N) {
    ll in; cin >> in;
    if(MAP[in] == 2) MAP[in] = 1;
    else MAP[in] = 2;
  }
  int ans = 0;
  for(auto m : MAP) if(m.second == 2) ans++;
  cout << ans << endl;
  return 0;
}
