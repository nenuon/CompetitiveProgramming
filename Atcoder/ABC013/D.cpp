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
  int amida[N+1];
  FOR(i,1,N+1) amida[amida0[i]] = i;
  // 周期チェック用
  int num[N+1];
  FOR(i,0,N+1) num[i] = i;
  int f = 0; // 周期
  do {
    f++;
    FOR(i,1,N+1) {
      num[i] = amida[num[i]];
    }
    bool ok = true;
    FOR(i,1,N+1) {
      if(num[i] != i) {
        ok = false;
        break;
      }
    }
    if(ok) break;
  } while(f < 40000);
  //cout << "f = " << f << endl;
  D %= f;
  int ans[N+1];
  FOR(i,0,N+1) ans[i] = i;
  FOR(i,0,D) {
    FOR(j,1,N+1) {
      ans[j] = amida[ans[j]];
    }
  }
  FOR(i,1,N+1) cout << ans[i] << endl;
  return 0;
}
