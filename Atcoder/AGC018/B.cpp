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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
int N, M;
int A[333][333];
bool flg[333];
int num[333];
int main()
{
  cin >> N >> M;
  FOR(i,0,N) FOR(j,0,M) {
    cin >> A[i][j];
    A[i][j]--;
  }
  FOR(i,0,M) flg[i] = true;
  int ans = 1000;
  FOR(i,0,M) {
    FOR(j,0,M) num[j] = 0;
    FOR(j,0,N) {
      int k = 0;
      FOR(k,0,M) {
        if(flg[A[j][k]]) {
          num[A[j][k]]++;
          break;
        }
      }
    }
    int cnt = 0;
    int mxm = 0;
    FOR(j,0,M) {
      if(cnt < num[j]) {
        mxm = j;
        cnt = num[j];
      }
    }
    ans = min(ans, cnt);
    flg[mxm] = false;
  }
  cout << ans << endl;
  return 0;
}
