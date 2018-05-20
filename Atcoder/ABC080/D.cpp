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
int tv[1000006][30];
int rec[1000006];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int C; cin >> C;
  FOR(i,0,N) {
    int s, t, c;
    cin >> s >> t >> c;
    c--;
    tv[s*10][c]++;
    tv[t*10][c]--;
  }
  FOR(i,0,1000005) {
    FOR(j,0,C) {
      if(tv[i][j] > 0) {
        rec[max(0, i - 5)]++;
      } else if(tv[i][j] < 0) {
        rec[i]--;
      } 
    }
  }
  int ans = rec[0];
  FOR(i,0,1000005) {
    rec[i+1] += rec[i];
    ans = max(ans, rec[i+1]);
  }
  cout << ans << endl;
  return 0;
}