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
typedef pair<int, int> P;
int main()
{
  int N, L; cin >> N >> L;
  cin.ignore();
  vector<string> vs(L);
  FOR(i,0,L) getline(cin, vs[i]);
  string s; getline(cin, s);
  //cout << s << endl;
  int o = 0;
  FOR(i,0,s.length()) {
    if(s[i] == 'o') {
      o = i / 2 + 1;
    }
  }
  vector<P> bou;
  for(int i = L - 1; i >= 0; i--) {
    FOR(j,0,(int)vs[i].length()) {
      if(vs[i][j] == '-') {
        int a = (j - 1) / 2 + 1;
        int b = (j + 1) / 2 + 1;
        bou.push_back(P(a, b));
      }
    }
  }
  int num[N*2]; FOR(i,0,N*2) num[i] = i;
  for(auto p : bou) {
    swap(num[p.first], num[p.second]);
  }
  FOR(i,0,2*N) {
    if(num[i] == o) {
      cout << i << endl;
      return 0;
    }
  }
}
