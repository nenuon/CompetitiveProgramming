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
  int C;
  cin >> C;
  int N[C], M[C], L[C];
  FOR(i,0,C) {
    int in[3];
    FOR(j,0,3) cin >> in[j];
    sort(in, in + 3);
    N[i] = in[0];
    M[i] = in[1];
    L[i] = in[2];
  }
  sort(N, N + C);
  sort(M, M + C);
  sort(L, L + C);
  cout << N[C-1] * M[C-1] * L[C-1] << endl;
  return 0;
}
