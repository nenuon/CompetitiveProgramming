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
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  FOR(i,0,h)cin>>s[i];
  vector<int> can(h,-1);
  FOR(i,0,h){
    if(can[i]!=-1)continue;
    FOR(j,i+1,h){
      if(can[j]!=-1)continue;
      // s[i]とs[j]がペアになれるか
      map<pair<char, char>, int> mp;
      FOR(k,0,w){
        mp[{s[i][k], s[j][k]}]++;
      }
      bool flag=true,able=w%2==1; // 奇数なら人組だけ真ん中
      for(auto k : mp){
        pair<char, char> p=k.first;
        // 絶対ペアでない
        if(mp.count({p.second,p.first})==0){
          flag=false;
          break;
        }
        if(mp[{p.second,p.first}]==k.second)continue;
        if(abs(mp[{p.second,p.first}]-k.second)==1){
          if(able)able=false;
          else{
            flag=false;
            break;
          }
        }
        // 絶対ペアでない
        if(abs(mp[{p.second,p.first}]-k.second)>1){
          flag=false;
          break;
        }
      }
      if(flag){
        can[i]=j;
        can[j]=i;
        break;
      }
    }
  }
  vector<string> t1,t2;
  string center;
  vector<bool> used(h, false);
  bool able=h%2==1;
  FOR(i,0,h){
    if(used[i])continue;
    if(can[i]==-1){
      if(able){
        center=s[i];
        used[i]=true;
        able=false;
        continue;
      }else{
        cout<<1<<endl;
        cout<<"NO"<<endl;
        return 0;
      }
    }
    t1.push_back(s[i]);
    used[i]=true;
    t2.push_back(s[can[i]]);
    used[can[i]]=true;
  }
  reverse(t2.begin(),t2.end());
  vector<string> t(t1);
  if(h%2)t.push_back(center);
  FOR(i,0,t2.size())t.push_back(t2[i]);

  able=w%2==1;
  used.assign(w,false);
  FOR(i,0,w){
    if(used[i])continue;
    // i列目と対応する列を見つける
    int idx=-1;
    FOR(j,0,w){
      if(i==j||used[j])continue;
      string tmp1="",tmp2="";
      FOR(k,0,h) tmp1+=t[k][i], tmp2+=t[k][j];
      reverse(tmp1.begin(),tmp1.begin());
      if(tmp1==tmp2){
        idx=j;
        used[i]=used[j]=true;
        break;
      }
    }
    if(idx==-1){
      if(able)able=false;
      else{
        cout<<2<<endl;
        cout<<"NO"<<endl;
        return 0;
      }
    }
  }
  cout<<"YES"<<endl;
  return 0;
}