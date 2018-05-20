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
// 残るのは高々3個
// 2個ずつ考える
// 例えば12->12,13,23でどっちか消える
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  bool r = 0, g = 0, b = 0;
  string s; cin >> s;
  for(int i = 0; i < N / 2 * 2; i += 2){
    if(s[i] == s[i+1]) continue;
    if(s[i] == 'R' || s[i+1] == 'R') r ^= 1;
    if(s[i] == 'G' || s[i+1] == 'G') g ^= 1;
    if(s[i] == 'B' || s[i+1] == 'B') b ^= 1;
  }
  if(N % 2 == 1) {
    if(s[N-1] == 'R') r ^= 1;
    if(s[N-1] == 'G') g ^= 1;
    if(s[N-1] == 'B') b ^= 1;
  }
  cout << r + g + b << endl;
  return 0;
}
