
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

int k, n;
int a[9];
vector<int> d[55];
string s[55];
string t[9];

bool dfs(int dep) {
  if(dep == k) {
    FOR(i,0,k) t[i] = "";
    FOR(i,0,n) {
      int p = 0; // 語呂のindex
      // 数字xのごろを作成
      for(int x : d[i]) {
        string y = ""; // とりあえずyに保存していく
        FOR(j,0,a[x]) {
          if(p < s[i].size()) {
            y += s[i][p];
            p++;
          }
        }
        if(y.size() != a[x]) return false; // 数字xのごろの長さが合っていない
        if(t[x] == "") t[x] = y; // 数字xのごろが決まってなかったらyにする
        else if(t[x] != y) return false; // すでに決まっててyでないならfalse
      }
      if(p != s[i].size()) return false;
    }
    FOR(i,0,k) cout << t[i] << endl;
    return true;
  }
  FOR(i,1,4) {
    a[dep] = i;
    if(dfs(dep+1)) return true;
  }
  return false;
}

int main()
{
  cin >> k >> n;
  FOR(i,0,n) {
    int x; cin >> x;
    cin >> s[i];
    while(x) {
      d[i].push_back(x%10 - 1);
      x /= 10;
    }
    reverse(d[i].begin(), d[i].end());
  }
  dfs(0);
  return 0;
}