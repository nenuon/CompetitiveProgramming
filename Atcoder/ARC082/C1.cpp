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
int r[100005];
int X,K,Q,T,A,s,l,k,t,x,f;
int main()
{
  f = -1;
  cin >> X >> K;
  FOR(i,0,K) cin >> r[i];
  s = 0; // 下限
  l = X; // 上限
  t = 0;
  k = 0;
  x = 0;
  for(cin>>Q;Q--;) {
    cin >> T >> A;
    while(k < K && T >= r[k]){
      int d = f * (r[k] - t); // 変化量
      x += d; // 全体の変化量
      s = min(X, max(0, s + d));
      l = min(X, max(0, l + d));
      t = r[k];
      k++;
      f *= -1;
    }
    int xx = min(l, max(s, A + x)) + f * (T - t);
    cout << min(X, max(0, xx)) << endl;
  }
  return 0;
}
