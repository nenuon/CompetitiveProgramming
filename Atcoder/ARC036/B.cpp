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
// 東から、西からそれぞれ数える
// その和が大きい場所が頂上となる山が答えの山
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int h[N]; FOR(i,0,N) cin >> h[i];
  int cnt = 0;
  int sz[N]; CLR(sz);
  FOR(i,1,N) {
    if(h[i] > h[i-1]) cnt++;
    else {
      cnt = 0;
    }
    sz[i] += cnt;
  }
  for(int i = N - 2; i >= 0; i--) {
    if(h[i+1] < h[i]) cnt++;
    else {
      cnt = 0;
    }
    sz[i] += cnt;
  }
  int mx = 0;
  FOR(i,0,N) mx = max(mx, sz[i]);
  cout << mx + 1 << endl;
  return 0;
}
