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
// 同じものが最大で何個繋がっているか調べる
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  bool col[N]; FOR(i,0,N) cin >> col[i];
  int cnt = 1;
  int mx = 0;
  FOR(i,0,2*N) {
    if(col[i%N] == col[(i+1)%N]) cnt++;
    else {
      mx = max(mx, cnt);
      cnt = 1;
    }
  }
  mx = max(mx, cnt);
  if(mx >= N) {
    cout << -1 << endl;
  } else {
    cout << (mx - 1) / 2 + 1 << endl;
  }
  return 0;
}
