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
  int N, M;
  cin >> N >> M;
  FOR(a,0,N+1) {
    int b = 4 * N - M - 2 * a;
    int c = N - a - b;
    if(b >= 0 && c >= 0) {
      printf("%d %d %d\n",a,b,c);
      return 0;
    }
  }
  printf("%d %d %d\n",-1 ,-1 ,-1);
  return 0;
}
