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

int main(){
  int A,B;
  cin>>A>>B;
  bool ok = false;
  if(A%3==0) ok = true;
  if(B%3==0) ok = true;
  if((A+B)%3==0) ok = true;
  cout << (ok ? "Possible" : "Impossible") << endl;
  return 0;
}
