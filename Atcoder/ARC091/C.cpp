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
stack<ll> tmp;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, A, B; cin >> N >> A >> B;
  if(B < (N + A - 1) / A || B > N - (A - 1)) {
    cout << -1 << endl;
    return 0;
  }
  if(A == N && B == 1) {
    FOR(i, 0, N) cout << i + 1 << " ";
  } else if(A == 1 && B == N) {
    FOR(i, 0, N) cout << N - i << " ";
  } else {
    for(int b = B; b > 0; b--) cout << b << " ";
    int cntMax = (N - B) / (A - 1);
    int cnt = 0;
    int up = (N - B) % (A - 1); /// up個は+1
    FOR(b,B+1,N+1) {
      tmp.push(b);
      cnt++;
      if(cnt == cntMax + (up > 0 ? 1 : 0)) {
        while(!tmp.empty()) {
          cout << tmp.top() << " ";
          tmp.pop();
        }
        cnt = 0;
        up--;
      }
    }
  }
  cout << endl;
  return 0;
}