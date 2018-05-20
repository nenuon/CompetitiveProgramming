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
const int inf = 1e9;

int main()
{
  string from, to;
  cin >> from >> to;
  if(from == to) {
    cout << 0 << endl;
    cout << from << endl;
    cout << to << endl;
    return 0;
  }

  int n;
  cin >> n;
  int m = n + 2;
  vector<string> s(m);
  s[0] = from;
  s[1] = to;
  FOR(i,2,m) {
    cin >> s[i];
  }

  vector<vector<int> > G(m);
  FOR(i,0,m) {
    FOR(j,i+1,m) {
      int c = 0;
      FOR(k,0,s[i].size()) {
        if(s[i][k]!=s[j][k]) c++;
      }
      if(c == 1) {
        G[i].push_back(j);
        G[j].push_back(i);
      }
    }
  }

  vector<int> prev(m, -1);
  prev[0] = 0;
  queue<int> Q;
  Q.push(0);
  while(!Q.empty() && prev[1] < 0) {
    for(int k : G[Q.front()]) {
      if(prev[k] < 0) {
        prev[k] = Q.front();
        Q.push(k);
      }
    }
    Q.pop();
  }

  if(prev[1] < 0) {
    cout << -1 << endl;
  } else {
    stack<int> st;
    st.push(1);
    int k = 1;
    do {
      k = prev[k];
      st.push(k);
    } while(k);

    cout << st.size() - 2 << endl;
    while(!st.empty()) {
      cout << s[st.top()] << endl;
      st.pop();
    }
  }
}
