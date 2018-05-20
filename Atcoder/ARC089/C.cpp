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
int t[100005], x[100005], y[100005];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  FOR(i,0,N) cin >> t[i+1] >> x[i+1] >> y[i+1];
  t[0] = x[0] = y[0] = 0;
  FOR(i,0,N) {
    int dt = t[i+1] - t[i];
    int dd = abs(x[i+1]-x[i]) + abs(y[i+1]-y[i]);
    int nokori = dt - dd;
    if(nokori < 0) {
      cout << "No" << endl;
      return 0;
    }
    if(nokori % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}