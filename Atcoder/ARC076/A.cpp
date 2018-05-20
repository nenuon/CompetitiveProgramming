#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
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
const long long mod = 1000000007;
int main(){
  long long n, m;
  cin >> n >> m;
  if(n - m >= 2 || n - m <= -2){
    cout << 0 << endl;
    return 0;
  }
  long long ans = 1;
  FOR(i,1,n+1){
    ans *= i;
    ans %= mod;
  }
  FOR(i,1,m+1){
    ans *= i;
    ans %= mod;
  }
  if(n == m) ans *= 2;
  cout << ans % mod << endl;
  return 0;
}
