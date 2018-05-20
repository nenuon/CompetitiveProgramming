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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

int main()
{
  int N;
  cin >> N;
  int a = 0, b = 0, c = 0;
  FOR(i,0,N) {
    ll in;
    cin >> in;
    if(in % 4 == 0) a++;
    else if(in % 2 == 0) b++;
    else c++;
  }
  if(b > 0) c++;
  if(c - 1 <= a || c == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
