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

// 1->maru,chokudai 2->batu,chokuko
// 点数の合計は同じ, chokukoはchokudaiの点数を最小化したい
int mass[3][3];
int b[2][3], c[3][2];
// chokudaiの点数を返す
int dfs(int n, int who) {
  if(n == 9) {
    int ret = 0;
    FOR(i,0,2) {
      FOR(j,0,3) {
        if(mass[i][j] == mass[i+1][j]) ret += b[i][j];
      }
    }
    FOR(i,0,3) {
      FOR(j,0,2) {
        if(mass[i][j] == mass[i][j+1]) ret += c[i][j];
      }
    }
    return ret;
  } else {
    // 次cokuko
    if(who == 1) {
      int ret = 0;
      FOR(i,0,3) {
        FOR(j,0,3) {
          if(mass[i][j] != 0) continue;
          mass[i][j] = 1;
          ret = max(ret, dfs(n + 1, 2));
          mass[i][j] = 0;
        }
      }
      return ret;
    } else {
      int ret = 1e9;
      FOR(i,0,3) {
        FOR(j,0,3) {
          if(mass[i][j] != 0) continue;
          mass[i][j] = 2;
          ret = min(ret, dfs(n + 1, 1));
          mass[i][j] = 0;
        }
      }
      return ret;
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int sum = 0;
  FOR(i,0,2) FOR(j,0,3) {
    cin >> b[i][j];
    sum += b[i][j];
  }
  FOR(i,0,3) FOR(j,0,2) {
    cin >> c[i][j];
    sum += c[i][j];
  }
  int chokudai = dfs(0, 1);
  cout << chokudai << endl;
  cout << sum - chokudai << endl;
  return 0;
}