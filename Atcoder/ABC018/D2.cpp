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
  int R,C,K; cin>>R>>C>>K;
  vector<string> vs(R);
  FOR(i,0,R) cin >> vs[i];
  int u[R][C], d[R][C];
  CLR(u);CLR(d);
  FOR(i,0,R) {
    FOR(j,0,C) {
      if(vs[i][j] == 'x') continue;
      //上に何個oがあるか
      int k = i - 1;
      while(k >= 0) {
        if(vs[k][j] == 'x') break;
        u[i][j]++;
        k--;
      }
      // 下
      k = i + 1;
      while(k < R) {
        if(vs[k][j] == 'x') break;
        d[i][j]++;
        k++;
      }
    }
  }
  int ans = 0;
  FOR(i,0,R) {
    FOR(j,0,C) {
      if(vs[i][j] == 'x') continue;
      bool ok = true;
      FOR(k,0,K) {
        int r = j + k;
        int l = j - k;
        if(r >= C || l < 0 || vs[i][r] == 'x' || vs[i][l] == 'x') {
          ok = false;
          break;
        }
        if(u[i][r] < ((K - k) * 2 - 1) / 2) {
          ok = false;
          break;
        }
        if(u[i][l] < ((K - k) * 2 - 1) / 2) {
          ok = false;
          break;
        }
        if(d[i][r] < ((K - k) * 2 - 1) / 2) {
          ok = false;
          break;
        }
        if(d[i][l] < ((K - k) * 2 - 1) / 2) {
          ok = false;
          break;
        }
      }
      ans += ok;
    }
  }
  cout << ans << endl;
  return 0;
}