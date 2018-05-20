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
  vector<string> vs(N);
  FOR(i,0,N) cin >> vs[i];
  int ans = 0;
  FOR(i,0,N) {
    for(int j = N - 1; j >= 0; j--) {
      if(vs[i][j] == '.') {
        ans++;
        if(i != N - 1) FOR(k, j, N) vs[i+1][k] = 'o';
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}