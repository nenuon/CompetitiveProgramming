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
ll llabs(ll x) {
  return x >= 0 ? x : -x;
}
int main(){
  int N;
  cin>>N;
  ll a[N];
  FOR(i,0,N) cin>>a[i];
  ll sunuke = 0, arai = 0;
  FOR(i,0,N) arai += a[i];
  ll ans = 1e15;
  FOR(i,0,N-1) {
    sunuke += a[i];
    arai -= a[i];
    ans = min(ans, llabs(arai - sunuke));
  }
  cout << ans << endl;
  return 0;
}
