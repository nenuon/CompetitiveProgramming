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
ll f(ll b, ll n) {
  if(n < b) return n;
  ll ret = n % b;
  ret += f(b, n / b);
  return ret;
}
int main()
{
  ll n, s;
  cin >> n >> s;
  if(n==s) {
    cout << n + 1 << endl;
    return 0;
  }
  FOR(i,2,sqrt(n)+1) {
    if(s == f(i, n)) {
      cout << i << endl;
      return 0;
    }
  }
  ll ans = 1e15;
  FOR(p,1,sqrt(n)+1) {
    if((n-s)%p==0 && (n-s)>=p) {
      if(s == f((n-s)/p+1, n)) {
        ans = min(ans, (n-s)/p+1);
      }
    }
  }
  if(ans != 1e15) {
    cout << ans << endl;
  } else {
    puts("-1");
  }
  return 0;
}
