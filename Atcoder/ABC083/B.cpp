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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int A, B; cin >> A >> B;
  int ans = 0;
  FOR(i,1,N+1) {
    int x = i;
    int wa = 0;
    while(x) {
      wa += x % 10;
      x /= 10;
    }
    if(wa >= A && wa <= B) ans += i;
  }
  cout << ans << endl;
  return 0;
}