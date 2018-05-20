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
vector<string> v, w;
int K, N;
int a[10];
string t[10];
bool dfs(int dep) {
  if(dep == K) {
    FOR(i,0,K) t[i] = "";
    FOR(i,0,N) {
      int p = 0;
      // ゴロを作って行く
      FOR(j,0,v[i].length()) {
        string y = "";
        int ind = (v[i][j] - '0') - 1;
        FOR(k,0,a[ind]) {
          if(p < w[i].length()) {
            y += w[i][p];
            p++;
          }
        }
        if(y.length() != a[ind]) return false;
        if(t[ind] == "") t[ind] = y;
        else if(t[ind] != y) return false;
      }
      if(p != w[i].length()) return false;
    }
    FOR(i,0,K) cout << t[i] << endl;
    return true;
  }
  FOR(i,1,4) {
    a[dep] = i;
    if(dfs(dep + 1)) return true;
  }
  return false;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> K >> N;
  FOR(i,0,N) {
    string a, b; cin >> a >> b;
    v.push_back(a);
    w.push_back(b);
  }
  dfs(0);
  return 0;
}