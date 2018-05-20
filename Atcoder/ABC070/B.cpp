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
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int sw[111]; FOR(i,0,111) sw[i] = 0;
  sw[a]++;sw[b]--;sw[c]++;sw[d]--;
  FOR(i,1,111) sw[i] += sw[i-1];
  int ans = 0;
  FOR(i,0,111) if(sw[i] == 2) ans++;
  cout << ans << endl;
  return 0;
}
