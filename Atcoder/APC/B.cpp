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
  int a[N], b[N];
  FOR(i,0,N) cin >> a[i];
  FOR(i,0,N) cin >> b[i];
  ll x = 0, y = 0;
  FOR(i,0,N) {
    if(a[i] < b[i]) {
      x += (b[i] - a[i]) / 2;
    } else if(a[i] > b[i]) {
      x -= a[i] - b[i];
    }
  }
  cout << (x >= 0 ? "Yes" : "No") << endl;
  return 0;
}