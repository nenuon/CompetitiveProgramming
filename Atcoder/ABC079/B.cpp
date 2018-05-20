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
#include <deque>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
ll memo[100];
ll f(int l) {
  if(memo[l] != -1) return memo[l];
  if(l == 0) return 2;
  if(l == 1) return 1;
  return memo[l] = f(l - 1) + f(l - 2);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  FOR(i,0,100) memo[i] = -1;
  cout << f(N) << endl;
  return 0;
}