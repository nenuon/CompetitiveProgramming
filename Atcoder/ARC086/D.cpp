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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int mx = -1e9, mn = 1e9;
  int mxi = -1, mni = -1;
  int a[N];
  FOR(i,0,N) {
    cin >> a[i];
    if(a[i] > mx) {
      mx = a[i];
      mxi = i;
    } else if(a[i] < mn){
      mn = a[i];
      mni = i;
    }
  }
  vector<P> ans;
  FOR(i,0,N-1) {
    if(a[i] > a[i+1]) {
      // 足した方が良いか引く方が良いか
      if(mn >= 0 || (((a[i] - a[i+1] + abs(mx) - 1) / abs(mx) <= (a[i] - a[i+1] + abs(mn) - 1) / abs(mn)) * (i + 1) && mx > 0)) {
        while(a[i] > a[i+1]) {
          a[i+1] += mx;
          ans.push_back(P(mxi+1,i+2));
          if(a[i+1] > mx) {
            a[i+1] = mx;
            mxi = i + 1;
          }
        }
      }
      // 引くしかない
      else {
        int j = i;
        while(j >= 0) {
          a[j] += mn;
          ans.push_back(P(mni+1,j+1));
          if(a[j] < mn) {
            a[j] = mn;
            mni = j;
          }
          j--;
        }
      }
    }
  }
  cout << ans.size() << endl;
  FOR(i,0,ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}