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
  int C[N-1], S[N-1], F[N-1];
  FOR(i,0,N-1) cin >> C[i] >> S[i] >> F[i];
  FOR(i,0,N-1) {
    int now = S[i] + C[i];
    FOR(j,i+1,N-1) {
      int x = max(0, (now - S[j] + F[j] - 1) / F[j]);
      now = S[j] + F[j] * x + C[j];
    }
    cout << now << endl;
  }
  cout << 0 << endl;
  return 0;
}
