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
  int A[N], B[N];
  FOR(i,0,N) {
    cin >> A[i];
    B[i] = A[i];
  }
  sort(B, B + N);
  map<int, bool> MAP;
  FOR(i,0,N) MAP[B[i]] = i & 1;
  int ans = 0;
  FOR(i,0,N) {
    if(MAP[A[i]] != (i & 1)) ans++;
  }
  cout << ans / 2 << endl;
  return 0;
}