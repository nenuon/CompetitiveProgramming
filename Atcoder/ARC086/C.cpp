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
int cnt[200001];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K; cin >> N >> K;
  int num = 0;
  FOR(i,0,N) {
    int in; cin >> in;
    if(cnt[in] == 0) num++;
    cnt[in]++;
  }
  sort(cnt, cnt + 200001);
  int nokori = num - K;
  int ans = 0;
  int i = 0;
  while(nokori > 0 && i <= 200001) {
    if(cnt[i] > 0) {
      ans += cnt[i];
      nokori--;
    }
    i++;
  }
  cout << ans << endl;
  return 0;
}