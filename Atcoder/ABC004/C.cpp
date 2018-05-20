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
  ll N;
  cin >> N;
  N %= 30;
  int num[6] = {1,2,3,4,5,6};
  FOR(i,0,N) {
    swap(num[i%5], num[i%5+1]);
  }
  FOR(i,0,6) {
    cout << num[i];
  }
  cout << endl;
  return 0;
}
