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
set<int> SET;
vector<int> g;
int main()
{
  int N, M;
  cin >> N >> M;
  FOR(i,0,M) {
    int aa, bb;
    cin >> aa >> bb;
    if(aa==1) {
      SET.insert(bb);
    }
    if(bb==N) {
      g.push_back(aa);
    }
  }
  FOR(i,0,g.size()) {
    if(SET.count(g[i])) {
      puts("POSSIBLE");
      return 0;
    }
  }
  puts("IMPOSSIBLE");
  return 0;
}
