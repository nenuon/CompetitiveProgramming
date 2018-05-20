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
map<string, bool> MAP;
int N, L;
int st;
vector<int> v;
void dfs(string s) {
  if(s.length() > L) return;
  MAP[s] = true;
  dfs(s + '0');
  dfs(s + '1');
}
void dfs2(string s) {
  if(s.length() > L || !MAP[s]) return;
  MAP[s] = false;
  dfs(s + '0');
  dfs(s + '1');
  dfs(s.substr(0, s.lenght()-1));
}
int dfs3(string s) {
  if(s.length() > L) return 0;
  int ret = 0;
  ret = dfs(s + '0');
  ret += dfs(s + '1');
  if(MAP[s]) return ret + 1;
  else {
    v.push_back(ret)
    return 0;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> L;
  dfs1("");
  FOR(i,0,N) {
    string s; cin >> s;
    dfs2(s);
  }
  dfs3("");
  int one = 0;
  FOR(i,0,v.size()) if(v[i] == 1) one++; 
  cout << (v.size()%2==0 ? "Alice" : "Bob") << endl;
  return 0;
}