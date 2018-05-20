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
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll Q,H,S,D,N; cin>>Q>>H>>S>>D>>N;
  vector<PP> yen(4);
  N *= 100;
  yen[0] = PP(Q * 8, P(Q, 25));
  yen[1] = PP(H * 4, P(H, 50));
  yen[2] = PP(S * 2, P(S, 100));
  yen[3] = PP(D * 1, P(D, 200));
  sort(yen.begin(), yen.end());
  ll ans = 0;
  FOR(i,0,4) {
    if(N <= 0) break;
    ans += (N / yen[i].second.second) * yen[i].second.first;
    N -= (N / yen[i].second.second) * yen[i].second.second;
  }
  cout << ans << '\n';
  return 0;
}
