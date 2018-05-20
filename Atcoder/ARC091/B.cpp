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
#include <deque>
#include <iomanip>
#include <limits>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K; cin >> N >> K;
  ll ans = 0;
  FOR(b,1,N+1) {
    int p = N / b;
    int r = N % b;
    ans += p * max(0, b - K) + max(0, r - K + 1);
    if(K == 0) ans--;
  }
  cout << ans << endl;
}