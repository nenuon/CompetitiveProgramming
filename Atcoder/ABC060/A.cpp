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
  string a,b,c;
  cin>>a>>b>>c;
  if(a[a.length()-1] == b[0] && b[b.length()-1] == c[0]) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
