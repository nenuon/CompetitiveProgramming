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
int to[100005][33]; // 2^j回でi->to[i]
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, M, D;
  cin >> N >> M >> D;
  int num[N + 1];
  FOR(i,0,N+1) {
    num[i] = i;
  }
  FOR(i,0,M) {
    int in;
    cin >> in;
    swap(num[in], num[in + 1]);
  }
  FOR(i,0,N+1) {
    to[num[i]][0] = i;
  }
  
    FOR(j,1,33) {
      FOR(i,0,N+1) {
      to[i][j] = to[to[i][j-1]][j-1];
    }
  }
  FOR(i,1,N+1) {
    int ret = i;
    int k = 0;
    ll DD = D;
    while (DD)
    {
      if(DD & 1) {
        ret = to[ret][k];
      }
      k++;
      DD >>= 1;
    }
    cout << ret << endl;
  }
  return 0;
}