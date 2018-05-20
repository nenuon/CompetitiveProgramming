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
#define FOR(I, A, B) for (int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define PI acos(-1)
typedef long long ll;
const double EPS = 1e-6;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int N;
  cin >> N;
  if (a > b)
    swap(a, b);
  FOR(i, 0, N)
  {
    int x, y;
    cin >> x >> y;
    if (x > y)
      swap(x, y);
    if (x > a && y > b)
    {
      cout << "YES" << endl;
      continue;
    }
    if (x <= a && y <= b)
    {
      cout << "NO" << endl;
      continue;
    }
    if (x > a)
    {
      double l = 0;
      double r = PI / 2;
      double m = (l + r) / 2;
      FOR(loop, 0, 100)
      {
        m = (l + r) / 2;
        double p = a * sin(m) + b * cos(m);
        if (p > y)
          l = m;
        else
          r = m;
      }
      if (a * cos(m) + b * sin(m) < x)
      {
        cout << "YES" << endl;
      }
      else
      {
        cout << "NO" << endl;
      }
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}