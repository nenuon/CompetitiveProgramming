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
#include <random>
#include <time.h>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

int main()
{
  int N; cin >> N;
  ll C[N]; FOR(i,0,N) cin >> C[i];
  double ans = 0;
  FOR(i,0,N) {
    int s = 0;
    // 約数の個数を数える
    FOR(j,0,N) {
      if(i == j) continue;
      if(C[i] % C[j] == 0) s++;
    }
    ans += double((s + 2) / 2) / (s + 1);
  }
  printf("%.010lf\n",ans);
  return 0;
}
