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
vector<int> x, y, X, Y;
bool check(int x_, int y_) {
  // 元の座標に戻す
  int px = (x_ + y_) / 2;
  int py = (x_ - y_) / 2;
  int d = abs(px - x[0]) + abs(py - y[0]);
  FOR(i,1,N) {
    if(d != abs(px - x[i]) + abs(py - y[i])) {
      return false;
    }
  }
  cout << px << " " << py << endl;
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  x.resize(N);
  y.resize(N);
  X.resize(N);
  Y.resize(N);
  FOR(i,0,N) {
    cin >> x[i] >> y[i];
    X[i] = x[i] + y[i];
    Y[i] = x[i] - y[i];
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  int D = max(X[N-1]-X[0], Y[N-1]-Y[0]);

  // 4パターン試す
  if(check(X[0]+D/2,Y[0]+D/2)){}
  else if(check(X[N-1]-D/2,Y[0]+D/2)){}
  else if(check(X[0]+D/2,Y[N-1]-D/2)){}
  else if(check(X[N-1]-D/2,Y[N-1]-D/2)){}
  return 0;
}