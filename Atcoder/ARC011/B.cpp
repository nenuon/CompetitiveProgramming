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
  int N;
  cin >> N;
  map<char, char> MAP;
  MAP['b'] = '1';
  MAP['c'] = '1';
  MAP['d'] = '2';
  MAP['w'] = '2';
  MAP['t'] = '3';
  MAP['j'] = '3';
  MAP['f'] = '4';
  MAP['q'] = '4';
  MAP['l'] = '5';
  MAP['v'] = '5';
  MAP['s'] = '6';
  MAP['x'] = '6';
  MAP['p'] = '7';
  MAP['m'] = '7';
  MAP['h'] = '8';
  MAP['k'] = '8';
  MAP['n'] = '9';
  MAP['g'] = '9';
  MAP['z'] = '0';
  MAP['r'] = '0';
  vector<string> ans;
  FOR(i,0,N) {
    string s;
    cin >> s;
    string ret = "";
    bool p = false;
    FOR(j,0,s.length()) {
      if((s[j]>='a'&&s[j]<='z') || (s[j]>='A'&&s[j]<='Z')) {
        s[j] = tolower(s[j]);
        if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='y') continue;
        ret += MAP[s[j]];
        p = true;
      }
    }
    if(p) ans.push_back(ret);
  }
  FOR(i,0,ans.size()) {
    printf("%s%c",ans[i].c_str(),i==ans.size()-1?'\n':' ');
  }
  if(ans.size()==0) cout << endl;
  return 0;
}
