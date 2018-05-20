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
#include <iomanip>
#include <limits>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string name = "MARCH";
  int N; cin >> N;
  ll cnt[5];
  CLR(cnt);
  FOR(i,0,N) {
    string s; cin >> s;
    FOR(j,0,5) {
      if(name[j] == s[0]) cnt[j]++;
    }
  }
  ll ans = 0;
  FOR(i,0,5) {
    FOR(j,i+1,5) {
      FOR(k,j+1,5) {
        ans += cnt[i] * cnt[j] * cnt[k];
      }
    }
  }
  cout << ans << endl;
}