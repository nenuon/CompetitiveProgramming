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
int calc(ll x) {
  int ret = 0;
  while(x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  vector<ll> ans;
  for(ll x = N; x >= N - 200 && x >= 1; x--) {
    if(calc(x) == N - x) ans.push_back(x);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  FOR(i,0,ans.size()) cout << ans[i] << endl;
  return 0;
}
