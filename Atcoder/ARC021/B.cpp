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
  int L; cin >> L;
  int B[L]; FOR(i,0,L) cin >> B[i];
  int b = 0;
  FOR(i,0,L) b ^= B[i];
  if(b == 0) {
    int A = 0;
    FOR(i,0,L) {
      cout << A << endl;
      A = B[i] ^ A;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
