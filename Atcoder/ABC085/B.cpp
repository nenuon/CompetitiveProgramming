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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int d[101];
  CLR(d);
  FOR(i,0,N) {
    int in; cin >> in;
    d[in]++;
  }
  int ans = 0;
  FOR(i,0,101) {
    if(d[i] > 0) ans++;
  }
  cout << ans << endl;
  return 0;
}