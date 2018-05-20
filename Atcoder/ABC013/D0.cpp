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
// Aは上からの横線なのでswapして行けば対応表作れる
int main()
{
  ll N, M, D;
  cin >> N >> M >> D;
  int amida0[N+1];
  FOR(i,0,N+1) amida0[i] = i;
  FOR(i,0,M) {
    int A;
    cin >> A;
    swap(amida0[A], amida0[A+1]);
  }

  // ダブリング用の配列作成
  int T = 32;
  int amida[T][N+1]; // 0(1回), 1(2回), 2(4回), 3(8回), ...
  FOR(i,1,N+1) amida[0][amida0[i]] = i;
  FOR(i,1,T) {
    FOR(j,1,N+1) {
      amida[i][j] = amida[i-1][amida[i-1][j]];
    }
  }
  int ans[N+1];
  FOR(i,0,N+1) ans[i] = i;
  FOR(i,1,N+1) {
    ll j = D;
    int k = 0;
    while(j > 0) {
      if(j & 1) {
        ans[i] = amida[k][ans[i]];
      }
      j >>= 1;
      k++;
    }
  }

  FOR(i,1,N+1) cout << ans[i] << endl;
  return 0;
}
