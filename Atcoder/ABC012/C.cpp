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
  int mx = 0;
  FOR(i,1,10) {
    FOR(j,1,10) {
      mx += i * j;
    }
  }
  int N;
  cin >> N;
  int fg = mx - N;
  FOR(i,1,10) {
    FOR(j,1,10) {
      if(i*j==fg) {
        printf("%d x %d\n",i,j);
      }
    }
  }
  return 0;
}
