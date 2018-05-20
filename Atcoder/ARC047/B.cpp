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
int N;
int x[100005], y[100005];
int X[100005], Y[100005];
bool check(int px, int py) {
  int x_ = (px + py) / 2;
  int y_ = (px - py) / 2;
  int d = abs(x_ - x[0]) + abs(y_ - y[0]);
  FOR(i,1,N) {
    if(d != abs(x_ - x[i]) + abs(y_ - y[i])) {
      return false;
    }
  }
  cout << x_ << " " << y_ << endl;
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  FOR(i,0,N) {
    cin >> x[i] >> y[i];
    X[i] = x[i] + y[i];
    Y[i] = x[i] - y[i];
  }
  sort(X, X + N);
  sort(Y, Y + N);
  int D = max(X[N-1] - X[0], Y[N-1] - Y[0]);
  if(check(X[0] + D / 2, Y[0] + D / 2)) {
  } else if(check(X[N-1] - D / 2, Y[0] + D / 2)) {
  } else if(check(X[0] + D / 2, Y[N-1] - D / 2)) {
  } else if(check(X[N-1] - D / 2, Y[N-1] - D / 2)) {
  }
  return 0;
}