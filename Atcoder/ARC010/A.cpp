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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M, A, B;
  cin >> N >> M >> A >> B;
  int c[M]; FOR(i,0,M) cin >> c[i];
  FOR(i,0,M) {
    if(N <= A) N += B;
    N -= c[i];
    if(N < 0) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  puts("complete");
  return 0;
}
