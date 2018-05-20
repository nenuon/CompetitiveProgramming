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
int N;
ll H[100005], S[100005];
// x[m]以下にできるかどうか
bool calc(ll x) {
  int T[N];
  FOR(i,0,N) {
    if(x - H[i] < 0) return false;
    T[i] = min((ll)111110, (x - H[i]) / S[i]);
  }
  sort(T, T + N);
  FOR(i,0,N) if(T[i] < i) return false;
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  FOR(i,0,N) cin >> H[i] >> S[i];
  ll l = 0, r = 1e16;
  while(r - l > 1) {
    ll m = (r + l) / 2;
    if(calc(m)) r = m;
    else l = m;
  }
  if(!calc(r)) r = l; 
  cout << r << endl;
  return 0;
}