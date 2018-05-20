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

int main(){
  int n;
  cin >> n;
  vector<string> vs;
  FOR(i,0,n) {
    string s;
    cin >> s;
    vs.push_back(s);
  }
  string ans = "";
  for (char c = 'a'; c <= 'z'; c++) {
    int len = 100;
    FOR (i,0,n) {
      int cnt = 0;
      FOR (j,0,vs[i].size()) {
        if(vs[i][j] == c) cnt++;
      }
      len = min(len, cnt);
    }
    FOR (i,0,len) {
      ans.push_back(c);
    }
  }
  cout << ans << endl;
  return 0;
}
