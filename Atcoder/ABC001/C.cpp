#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
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
const string s[] = {"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","N"};
const int a[] = {25,155,335,545,795,1075,1385,1715,2075,2445,2845,3265, 100000000};
int main(){
  int deg, dis;
  cin >> deg >> dis;

  int i = 0;
  while(deg * 10 >= 1125 + 2250 * i) i++;

  int j = 0;
  while(dis * 10 >= a[j] * 6) j++;

  if(j == 0) cout << "C " << j <<  endl;
  else cout << s[i] << " " << j << endl;
  return 0;
}
