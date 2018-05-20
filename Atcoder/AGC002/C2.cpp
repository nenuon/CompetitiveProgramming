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
  int N, L; cin >> N >> L;
  ll a, b; cin >> a;
  int j = -1;
  ll mx = 0;
  FOR(i,1,N) {
    cin >> b;
    if(mx < a + b) {
      mx = a + b;
      j = i;
    }
    a = b;
  }
  if(mx >= L) {
    cout << "Possible" << endl;
    FOR(i,1,N) {
      if(i == j) break;
      cout << i << endl;
    }
    for(int i = N - 1; i >= 1; i--) {
      if(i == j) break;
      cout << i << endl;
    }
    cout << j << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
} 