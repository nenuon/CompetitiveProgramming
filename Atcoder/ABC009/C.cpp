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
  int N, K; cin >> N >> K;
  string s; cin >> s;
  vector<char> vc;
  FOR(i,0,s.length()) vc.push_back(s[i]);
  sort(vc.begin(), vc.end());
  int ch = 0;
  string ans = "";
  FOR(i,0,s.length()) {
    // vc[j]をiに持ってくる
    bool next = false;
    int vclen = s.length() - i;
    FOR(j,0,vclen) {
      int ch1 = 0, ch2 = 0;
      int a[26], b[26]; FOR(l,0,26) a[l] = b[l] = 0;
      FOR(l,i+1,s.length()) a[s[l]-'a']++;
      FOR(l,0,vclen) {
        if(l == j) continue;
        b[vc[l]-'a']++;
      }
      if(vc[j] != s[i]) ch1++;
      // 残りはどれだけことなっているか
      FOR(l,0,26) ch2 += abs(a[l] - b[l]);
      ch2 >>= 1;
      if(ch + ch1 + ch2 <= K) {
        ch += ch1;
        ans += vc[j];
        vc.erase(vc.begin() + j);
        next = true;
        break;
      }
    }
    if(!next) {
      ans += s[i];
      FOR(j,0,vclen) if(vc[j] == s[i]) vc.erase(vc.begin() + j);
    }
  }
  cout << ans << endl;
  return 0;
}
