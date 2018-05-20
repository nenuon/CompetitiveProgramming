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
  return x > 0 ? x : - x;
}
int main()
{
  ll X, Y;
  cin >> X >> Y;
  if(llabs(X-Y)<=1) {
    cout << "Brown" << endl;
  } else {
    cout << "Alice" << endl;
  }
  return 0;
}
