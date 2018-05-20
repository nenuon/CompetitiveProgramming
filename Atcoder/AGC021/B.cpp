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
#include <iomanip>
#include <limits>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define PI acos(-1)
typedef long long ll;
// tourist answer
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  FOR(i,0,n) cin >> x[i] >> y[i];
  int num = 250000;
  double r = 1e11;
  double ans[n];
  CLR(ans);
  FOR(i,0,num+1) {
    double theta = i * 2.0 * PI / num;
    double X = r * cos(theta);
    double Y = r * sin(theta);
    double mn = 1e30;
    int best = 0;
    FOR(j,0,n) {
      double dist = sqrt(pow(x[j]-X,2)+pow(y[j]-Y,2));
      if(dist < mn) {
        mn = dist;
        best = j;
      }
    }
    ans[best] += 1.0 / num;
  }
  FOR(i,0,n) cout << fixed << setprecision(17) << ans[i] << endl;
  return 0;
}