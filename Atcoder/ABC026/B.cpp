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
  ll N; cin >> N;
  if(N == 1) {
    puts("Deficient");
    return 0;
  }
  ll sum = 1;
  FOR(i,2,sqrt(N)) {
    if(N % i == 0) {
      sum += i;
      sum += N / i;
    }
  }
  if(sum == N) puts("Perfect");
  else if(sum > N) puts("Abundant");
  else puts("Deficient");
  return 0;
}
