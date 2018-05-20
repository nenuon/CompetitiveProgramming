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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<string> vs(N); FOR(i,0,N) cin >> vs[i];
  set<string> SET;
  SET.insert(vs[0]);
  FOR(i,1,N) {
    if(vs[i-1][(int)vs[i-1].length()-1] != vs[i][0]) {
      if(i % 2 == 1) {
        puts("WIN");
      } else {
        puts("LOSE");
      }
      return 0;
    }
    if(SET.count(vs[i])) {
      if(i % 2 == 1) {
        puts("WIN");
      } else {
        puts("LOSE");
      }
      return 0;
    }
    SET.insert(vs[i]);
  }
  puts("DRAW");
  return 0;
}
