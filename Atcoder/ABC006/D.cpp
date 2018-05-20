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

int main()
{
  int N;
  cin>>N;
  vector<int> len(N+1);
  len[0] = 0;
  FOR(i,1,N+1) len[i] = 1e9;
  FOR(i,0,N) {
    int c;
    cin >> c;
    int j = upper_bound(len.begin(), len.end(), c) - len.begin();
    len[j] = c;
    /*
    FOR(j,0,N) {
      if(len[j] < c && len[j+1] > c) {
        len[j+1] = c;
        break;
      }
    }
    */
  }
  int ans_ = 0, ans = 0;
  FOR(i,1,N+1) {
    if(len[i]==1e9) break;
    ans_++;
  }
  ans = N - ans_;
  cout << ans << endl;
  return 0;
}
