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
  int N, M;
  cin >> N >> M;
  bool fr[N][N];
  FOR(i,0,N) FOR(j,0,N) fr[i][j] = false;
  int ans = 0;
  FOR(i,0,M) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    fr[a][b] = fr[b][a] = true;
  }
  FOR(i,0,1<<N) {
    vector<int> v;
    FOR(j,0,N) {
      if((i>>j)&1) v.push_back(j);
    }
    bool ok = true;
    int len = v.size();
    FOR(j,0,len-1) {
      FOR(k,j+1,len) {
        if(!fr[v[j]][v[k]]) ok = false;
      }
    }
    if(ok) ans = max(ans, len);
  }
  cout << ans << endl;
  return 0;
}
