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
bool ex[26];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;cin>>s;
  if(s.length()==26){
    vector<char> v;
    FOR(i,0,26)v.push_back(s[i]);
    if(next_permutation(v.begin(),v.end())){
      FOR(i,0,26){
        cout<<v[i];
        if(s[i]!=v[i]){
          cout<<endl;
          return 0;
        }
      }
    }
    else cout<<-1<<endl;
  }else{
    FOR(i,0,s.length())ex[s[i]-'a']=true;
    FOR(i,0,26){
      if(!ex[i]){
        cout<<s<<char(i+'a')<<endl;
        return 0;
      }
    }
  }
}