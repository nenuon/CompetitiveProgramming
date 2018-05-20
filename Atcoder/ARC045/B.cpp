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
  int N, M; cin >> N >> M;
  int room[N+2]; CLR(room);
  int s[M], t[M];
  FOR(i,0,M) {
    cin >> s[i] >> t[i];
    room[s[i]]++;
    room[t[i]+1]--;
  }
  FOR(i,0,N+1) {
    room[i+1] += room[i];
  }
  // roomが2以上のところはサボれる
  stack<int> st;
  int lr[N+1]; 
  FOR(i,1,N+2) {
    st.push(i);
    if(room[i] <= 1) {
      int j = 0;
      while(!st.empty()) {
        lr[st.top()] = j;
        st.pop();
        j++;
      }
    }
  }
  int k = 0;
  vector<int> ans;
  FOR(i,0,M) {
    if(lr[s[i]] >= (t[i] - s[i] + 1)) {
      k++;
      ans.push_back(i+1);
    }
  }
  cout << k << endl;
  FOR(i,0,ans.size()) cout << ans[i] << endl;
  return 0;
}