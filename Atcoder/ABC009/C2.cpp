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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  string s;
  cin>>n>>m>>s;
  string t=s;
  sort(t.begin(),t.end());
  int ch=0;
  string ans="";
  FOR(i,0,n){
    // t[j]をiに持ってくる
    bool next=false;
    int tlen=n-i;
    FOR(j,0,tlen){
      int ch1=0,ch2=0;
      int a[26],b[26];
      CLR(a);CLR(b);
      FOR(l,i+1,n) a[s[l]-'a']++;
      FOR(l,0,tlen){
        if(l==i)continue;
        b[t[l]-'a']++;
      }
      if(t[j]!=s[i])ch1++;
      FOR(l,0,26)ch2+=abs(a[l]-b[l]);
      ch2>>=1;
      if(ch+ch1+ch2<=m){
        ch+=ch1;
        ans+=t[j];
        t.erase(t.begin()+j);
        next=true;
        break;
      }
    }
    if(!next){
      ans+=s[i];
      FOR(j,0,tlen){
        if(t[j]==s[i])t.erase(t.begin()+j);
      }
    }
  }
  cout<<ans<<endl;
}