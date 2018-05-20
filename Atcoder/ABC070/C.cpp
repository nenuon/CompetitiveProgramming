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
//最大公約数
ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) a %= b;
    else b %= a;
  }
  return a + b;
}
//最小公倍数
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b;}
int main()
{
  int N; cin >> N;
  ll ans = 1;
  FOR(i,0,N) {
    ll in; cin >> in;
    ans = lcm(ans, in);
  }
  cout << ans << endl;
  return 0;
}
