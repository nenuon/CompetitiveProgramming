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
  ll N, A, B;
  cin >> N >> A >> B;
  if(A == B) {
    if(N % (B + 1) == 0) {
      puts("Aoki");
    } else {
      puts("Takahashi");
    }
  } else {
    if (A > B || A >= N) {
      puts("Takahashi");
    } else {
      puts("Aoki");
    }
  }
  
  return 0;
}