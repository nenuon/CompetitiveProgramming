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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
int W,H;
bool exist[100][100];
int calc(int y, int x) {
  if(!exist[y][x]) return 0;
  exist[y][x] = false;
  int ret = 1;
  FOR(i,1,1e9) {
    if(exist[y+i][x]) {
      exist[y+i][x] = false;
      ret++;
    } else break;
  }
  FOR(i,1,1e9) {
    if(y-i>=0 && exist[y-i][x]) {
      exist[y-i][x] = false;
      ret++;
    } else break;
  }
  FOR(i,1,1e9) {
    if(exist[y][x+i]) {
      exist[y][x+i] = false;
      ret++;
    } else break;
  }
  FOR(i,1,1e9) {
    if(x-i>=0 && exist[y][x-i]) {
      exist[y][x-i] = false;
      ret++;
    } else break;
  }
  return ret;
}
int main()
{
  cin >> W >> H;
  if(W > 80 || H > 80) return 0;
  int N; cin >> N;
  if(N > 8) return 0;
  int X[N], Y[N];
  FOR(i,0,N) {
    cin >> X[i] >> Y[i];
    X[i]--;Y[i]--;
  }
  int idx[N];
  FOR(i,0,N) idx[i] = i;
  int ans = 0;
  do {
    FOR(i,0,H) FOR(j,0,W) exist[i][j] = true;
    int ret = 0;
    FOR(i,0,N) {
      ret += calc(Y[idx[i]], X[idx[i]]);
    }
    ans = max(ans, ret);
  } while(next_permutation(idx, idx+N));
  cout << ans << endl;
  return 0;
}
