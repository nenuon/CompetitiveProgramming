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
// 多くてもN回
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int a[N+1]; FOR(i,1,N+1) cin >> a[i];
  int now = 1;
  FOR(i,0,N+1) {
    if(now == 2) {
      cout << i << '\n';
      return 0;
    }
    now = a[now];
  }
  cout << -1 << endl;
  return 0;
}
