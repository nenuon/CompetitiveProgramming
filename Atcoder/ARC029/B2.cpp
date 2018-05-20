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
#define PI acos(-1)
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A, B; cin >> A >> B;
  if(A > B) swap(A, B);
  int N; cin >> N;
  FOR(i,0,N) {
    int C, D; cin >> C >> D;
    if(C > D) swap(C, D);
    if(A < C && B < D) {
      cout << "YES" << endl;
      continue;
    }
    if(A >= C && B >= D) {
      cout << "NO" << endl;
      continue;
    }
    if(A < C) {
      // 二分探索
      double l = 0;
      double r = PI / 2;
      double m = (l + r) / 2;
      FOR(loop, 0, 100) {
        m = (l + r) / 2;
        // x方向のながさ
        double d = B * cos(m) + A * sin(m);
        if(d > D) l = m;
        else r = m; 
      }
      // y方向の長さが収まっていればok
      if(B * sin(m) + A * cos(m) < C) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
}