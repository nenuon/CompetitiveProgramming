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
typedef pair<ll, int> P;
bool used[300005];
priority_queue<ll, vector<ll>, greater<ll> > Q1;
priority_queue<P, vector<P>, greater<P> > Q2;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int a[3*N]; FOR(i,0,3*N) cin >> a[i];
  CLR(used);
  vector<pair<int, int> > b;
  // どこで前半後半きれるか全探索
  ll pre = 0, bak = 0;
  FOR(i,0,N) {
    pre += a[i];
    Q1.push(a[i]);
  }
  FOR(i,N,3*N) {
    b.push_back(make_pair(a[i], i));
  }
  sort(b.begin(), b.end());
  FOR(i,0,N) {
    bak += b[i].first;
    used[b[i].second] = true;
  }
  FOR(i,N,2*N) {
    Q2.push(P(b[i].first, b[i].second));
  }
  ll ans = pre - bak;
  FOR(i,N,2*N) {
    Q1.push(a[i]);
    pre += a[i];
    pre -= Q1.top();
    Q1.pop();
    if(used[i]) {
      P p = Q2.top(); Q2.pop();
      while(used[p.second] && !Q2.empty()) p = Q2.top(),Q2.pop();
      used[p.second] = true;
      bak -= a[i];
      bak += p.first;
    }
    used[i] = true;
    ans = max(ans, pre - bak);
  }
  cout << ans << endl;
  return 0;
}