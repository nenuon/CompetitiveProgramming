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
  int n;
  cin >> n;
  ll a[n];
  FOR(i,0,n) scanf("%lld", a + i);
  vector<ll> b(n);
  int r = n - 1;
  int l = 0;
  FOR(i,0,n) {
    if(i % 2 == 0) {
      b[l] = a[n - 1 - i];
      l++;
    }
    else {
      b[r] = a[n - 1 - i];
      r--;
    }
  }
  //reverse(b.begin(), b.end());
  FOR(i,0,n){
    printf("%lld%c", b[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}
