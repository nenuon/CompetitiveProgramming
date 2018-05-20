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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, a; cin >> N >> a;
  string k; cin >> k;
  int b[N]; FOR(i,0,N) cin >> b[i];
  ll kk = 0;
  ll done = 0;
  if(k.length() < 6) kk = stoi(k);
  int vis[N+1]; CLR(vis);
  vis[a]++;
  while(1) {
    done++;
    a = b[a-1];
    vis[a]++;
    if(vis[a] == 2) break;
    if(kk == done) {
      cout << a << endl;
      return 0;
    }
  }
  ll c = 0; // ループの長さ
  while(1) {
    a = b[a-1];
    vis[a]++;
    c++;
    if(vis[a] == 3) break;
  }
  // 残りk-done回
  ll nokori = 0;
  FOR(i,0,k.length()) {
    nokori = (nokori * 10) % c;
    nokori += k[i] - '0';
  }
  nokori = (nokori - done % c + c) % c;
  FOR(i,0,nokori) a = b[a-1];
  cout << a << endl;
  return 0;
}