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

int main()
{
  int A, B, C;
  cin >>A>>B>>C;
  FOR(i,0,1000) {
    if((A*i)%B==C) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
