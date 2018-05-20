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
typedef pair<int, int> P;
vector<P> ans;
int N;
int a[100];
void solve(bool plus) {
  if(plus) {
    FOR(i,0,N-1) {
      ans.push_back(P(i+1,i+2));
    }
  } else {
    for(int i = N - 1; i > 0; i--) {
      ans.push_back(P(i + 1, i));
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  FOR(i,0,N) cin >> a[i];
  int MAX = -1e9, MIN = 1e9;
  int mxi = -1, mni = -1;
  bool minus = false, plus = false;
  FOR(i,0,N) {
    if(MAX < a[i]) {
      MAX = a[i];
      mxi = i;
    }
    if(MIN > a[i]) {
      MIN = a[i];
      mni = i;
    }
    if(a[i] >= 0) plus = true;
    if(a[i] < 0) minus = true;
  }

  if(plus && minus) {
    if(abs(MAX) >= abs(MIN)) {
      FOR(i,0,N) {
        ans.push_back(P(mxi+1,i+1));
        a[i] += MAX;
      }
      solve(1);
    } else {
      FOR(i,0,N) {
        ans.push_back(P(mni+1,i+1));
        a[i] += MIN;
      }
      solve(0);
    }
  } else if(plus) {
    solve(1);
  } else {
    solve(0);
  }
  cout << ans.size() << endl;
  FOR(i,0,ans.size()) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}