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
int b[10];
bool comp(string s1, string s2) {
  if((int)s1.length() < (int)s2.length()) return true;
  else if((int)s1.length() > (int)s2.length()) return false;
  FOR(i,0,(int)s1.length()) {
    if(b[s1[i]-'0'] < b[s2[i]-'0']) return true;
    else if(b[s1[i]-'0'] > b[s2[i]-'0']) return false;
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  FOR(i,0,10) {
    int in; cin >> in;
    b[in] = i;
  }
  int N; cin >> N;
  vector<string> a(N); FOR(i,0,N) cin >> a[i];
  sort(a.begin(), a.end(), comp);
  FOR(i,0,N) cout << a[i] << endl;
  return 0;
}
