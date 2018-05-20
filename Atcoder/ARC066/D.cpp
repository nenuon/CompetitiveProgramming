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
#include <deque>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  FOR(a,0,10) {
    FOR(b,0,10) {
      cout << "a = " << a << " b = " << b << endl;
      cout << "u = " << (a ^ b) << " v = " << (a + b) << endl;
      cout << endl;
    }
  }
  return 0;
}