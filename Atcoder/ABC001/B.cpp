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

int main(){
  double m;
  cin >> m;
  m /= 1000;
  int ans;
  if(m<0.1) ans = 0;
  else if(m<=5) ans = m * 10;
  else if(m>=6 && m<=30) ans = m + 50;
  else if(m >= 35 && m <= 70){
    ans = m - 30;
    ans /= 5;
    ans += 80;
  }
  else ans = 89;
  cout << setw(2) << setfill('0') << ans << endl;
  return 0;
}
