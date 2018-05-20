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
typedef pair<int, int> P;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W, D;
  cin >> H >> W >> D;
  int A[H][W];
  P num[H*W+1];
  FOR(i,0,H) {
    FOR(j,0,W) {
      cin >> A[i][j];
      num[A[i][j]] = P(i, j);
    }
  }
  int cost[H*W+1];
  FOR(i,1,D+1) {
    int x = i;
    cost[i] = 0;
    int cnt = 1;
    while(x + D <= H * W) {
      // x -> x + D
      cost[x+D] = cost[x] + abs(num[x].first-num[x+D].first) + abs(num[x].second-num[x+D].second);
      x += D;
      cnt++;
    }
  }
  int Q; cin >> Q;
  
  FOR(i,0,Q) {
    int L, R; cin >> L >> R;
    cout << cost[R] - cost[L] << endl;
  }
}