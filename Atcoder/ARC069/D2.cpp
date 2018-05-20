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
bool h[100005];
string s;
int N;
bool check() {
  FOR(i,0,N) {
    int j = (i + 1) % N; // 真ん中
    int k = (j + 1) % N;
    // 羊の時
    if(h[j]) {
      if(j == N - 1 || j == 0) {
        if(s[j] == 'o' && h[i] != h[k]) return false;
        if(s[j] == 'x' && h[i] == h[k]) return false;
      }
      else h[k] = s[j] == 'o' ? h[i] : h[i] ^ 1;
    } else { 
      if(j == N - 1 || j == 0) {
        if(s[j] == 'o' && h[i] == h[k]) return false;
        if(s[j] == 'x' && h[i] != h[k]) return false;
      }
      else h[k] = s[j] == 'o' ? h[i] ^ 1 : h[i];
    }
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  cin >> s;
  // 羊羊
  h[0] = h[1] = true;
  if(check()) {
    FOR(i,0,N) cout << (h[i] ? 'S' : 'W');
    cout << endl;
    return 0;
  }
  // 羊狼
  h[0] = true;
  h[1] = false;
  if(check()) {
    FOR(i,0,N) cout << (h[i] ? 'S' : 'W');
    cout << endl;
    return 0;
  }
  // 狼羊
  h[0] = false;
  h[1] = true;
  if(check()) {
    FOR(i,0,N) cout << (h[i] ? 'S' : 'W');
    cout << endl;
    return 0;
  }
  // 狼狼
  h[0] = h[1] = false;
  if(check()) {
    FOR(i,0,N) cout << (h[i] ? 'S' : 'W');
    cout << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}