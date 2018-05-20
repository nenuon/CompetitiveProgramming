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
  string s; cin >> s;
  int cnt = 0;
  FOR(i,0,N) {
    FOR(j,0,5) {
      char x = 'A' + j;
      if(s[i] == x) cnt += 4 - j;
    }
  }
  printf("%.10lf\n",(double)cnt/N);
  return 0;
}
