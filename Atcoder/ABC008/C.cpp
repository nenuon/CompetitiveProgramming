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
  if(N > 8) return 0;
  vector<ll> C(N); FOR(i,0,N) cin >> C[i];
  sort(C.begin(), C.end());
  int cnt = 0, nd = 0;
  do {
    int omote[N]; FOR(i,0,N) omote[i] = true;
    FOR(i,0,N) FOR(j,i+1,N) if(C[j]%C[i]==0) omote[j] ^= 1;
    FOR(i,0,N) cnt += omote[i];
    nd++;
  } while(next_permutation(C.begin(), C.end()));
  printf("%.010lf\n",double(cnt)/nd);
  return 0;
}
