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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  int na, nb; cin >> na >> nb;
  map<ll, int> cnt;
  FOR(i,0,na) {
    ll in; cin >> in;
    cnt[in]++;
  }
  FOR(i,0,nb) {
    ll in; cin >> in;
    cnt[in]++;
  }
  int AND = 0, OR = 0;
  for(auto m : cnt) {
    if(m.second >= 1) OR++;
    if(m.second == 2) AND++;
  }
  printf("%.10lf\n",(double)AND/OR);
  return 0;
}
