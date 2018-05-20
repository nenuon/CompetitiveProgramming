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
typedef pair<ll, ll> P;
// 飴があるとこだとダブルけどKこの所をさがす
// ちょうど飴があるところでK個となったら本当はK-1個
// ちょうど飴があるところでK+1個となったら本当はK個
ll r[100005], c[100005]; // r , c に何個あるか
vector<P> candies;
ll rows[100005], cols[100005];
int main()
{
  int R, C, K, N;
  cin >> R >> C >> K >> N;
  FOR(i,0,100005) r[i] = 0;
  FOR(i,0,100005) c[i] = 0;
  FOR(i,0,100005) rows[i] = cols[i] = 0;
  FOR(i, 0, N) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    r[a]++;
    c[b]++;
    candies.push_back(P(a, b));
  }
  ll ans = 0;
  FOR(i, 0, N) {
    P p = candies[i];
    // 本当はK個
    if(r[p.first] + c[p.second] == K + 1) ans++;
    // 本当はK-1個
    if(r[p.first] + c[p.second] == K) ans--;
  }

  // x個の行、列が何個あるか
  FOR(i, 0, R) rows[r[i]]++;
  FOR(i, 0, C) cols[c[i]]++;
  FOR(i,0,K+1) {
    ans += rows[i] * cols[K-i];
  }
  cout << ans << endl;
  return 0;
}
