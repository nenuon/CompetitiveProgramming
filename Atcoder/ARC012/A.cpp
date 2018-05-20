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
  string s; cin >> s;
  map<string, int> MAP;
  MAP["Sunday"] = 0;
  MAP["Monday"] = 5;
  MAP["Tuesday"] = 4;
  MAP["Wednesday"] = 3;
  MAP["Thursday"] = 2;
  MAP["Friday"] = 1;
  MAP["Saturday"] = 0;
  cout << MAP[s] << endl;
  return 0;
}
