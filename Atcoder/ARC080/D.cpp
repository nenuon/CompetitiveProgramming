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

int main()
{
  int H, W;
  cin >> H >> W;
  int N;
  cin >> N;
  int a[N];
  FOR(i,0,N) cin >> a[i];
  int now = 1;
  int ans[H][W];
  FOR(y,0,H) {
    if(y % 2 == 0) {
      FOR(x,0,W) {
        if(a[now-1]==0) now++;
        ans[y][x] = now;
        a[now-1]--;
      }
    }
    if(y % 2 == 1) {
      for(int x = W - 1; x >= 0; x--) {
        if(a[now-1]==0) now++;
        ans[y][x] = now;
        a[now-1]--;
      }
    }
  }
  FOR(y,0,H) {
    FOR(x,0,W) {
      printf("%d%c",ans[y][x],x==W-1?'\n':' ');
    }
  }
  return 0;
}
