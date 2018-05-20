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
const ll MOD = 1000000007;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, A, B; cin >> N >> A >> B;
  ll a[N];
  priority_queue<ll, vector<ll>, greater<ll> > Q;
  FOR(i,0,N) {
    cin >> a[i];
    Q.push(a[i]);
  }
  sort(a, a + N);
  if(A == 1) {
    FOR(i,0,N) cout << a[i] % MOD << endl;
    return 0;
  }
  while(Q.top() < a[N-1]) {
    B--;
    ll q = Q.top(); Q.pop();
    Q.push(q * A);
    if(B == 0) break;
  }
  FOR(i,0,N) {
    a[i] = Q.top();
    Q.pop();
  }
  if(B == 0) {
    FOR(i,0,N) cout << a[i] % MOD << endl;
    return 0;
  }
  // 残りB回N回周期
  FOR(i,0,N) {
    int j = (i + B % N) % N;
    ll x = a[j] % MOD;
    ll t = j < B % N ? B / N + 1 : B / N;
    ll AA = A % MOD;
    // ダブリング
    while(t) {
      if(t & 1) x = (x * AA) % MOD;
      AA = (AA * AA) % MOD;
      t >>= 1;
    }
    cout << x << endl;
  }
  return 0;
}