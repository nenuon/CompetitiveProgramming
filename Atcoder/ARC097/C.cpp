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
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
priority_queue<string> vs;
set<string> S;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;cin>>s;
  int K;cin>>K;
  int n=s.length();
  FOR(i,0,n){
    string str = "";
    str += s[i];
    if(vs.size()==K){
      if(str>vs.top())continue;
    }
    if(S.count(str)==0){
      vs.push(str);
    if(vs.size()==K+1)vs.pop();
    }
    S.insert(str);
    FOR(j,i+1,n){
      str += s[j];
      if(vs.size()==K){
      if(str>vs.top())continue;
    }
      if(S.count(str)==0){
      vs.push(str);
    if(vs.size()==K+1)vs.pop();
    }
      S.insert(str);
    }
  }
  vector<string> ans;
  while(!vs.empty()){
    ans.push_back(vs.top());
    vs.pop();
  }
  sort(ans.begin(),ans.end());
  cout<<ans[K-1]<<endl;
}