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
int main()
{
  //ios::sync_with_stdio(false);
  //cin.tie(0);
  int N; cin >> N;
  cout << 0 << endl;
  string s; cin >> s;
  if(s[0] == 'V') return 0;
  if(N <= 20) {
    FOR(i,1,20) {
      cout << i << endl;
      cin >> s;
      if(s[0] == 'V') return 0;
    }
  }
  bool male = s[0] == 'M';
  int l = 0, r = N;
  FOR(i, 0, 19) {
    int cen = (l + r) / 2;
    cout << cen << endl;
    cin >> s;
    if(s[0] == 'V') return 0;
    // male と同じなら左にある
    if(cen % 2 == 0) {
      if(male ^ (s[0] == 'M')) {
        r = cen; // 違うなら時計方向
      } else {
        l = cen; // 同じなら反時計回り方向
      }
    }
    // maleと違うなら左にある 
    else {
      if(male ^ (s[0] == 'M')) {
        l = cen;
      } else {
        r = cen;
      }
    }
  }
  return 0;
}