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

int main()
{
  int Y; cin >> Y;
  bool uruu = false;
  if(Y % 400 == 0) uruu = true;
  else if(Y % 100 == 0) uruu = false;
  else if(Y % 4 == 0) uruu = true;
  puts(uruu?"YES":"NO");
  return 0;
}
