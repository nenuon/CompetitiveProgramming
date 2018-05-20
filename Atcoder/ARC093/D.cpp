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
vector<string> ans;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A,B;cin>>A>>B;
  A--;B--;
  FOR(i,0,100){
    string s="";
    FOR(j,0,50)s+='#';
    FOR(j,50,100)s+='.';
    ans.push_back(s);
  }
  int cnt=0;
  for(int h=1;h<100&&cnt<A;h+=2){
    for(int w=1;w<49&&cnt<A;w+=2){
        ans[h][w]='.';
        cnt++;
    }
  }
  cnt=0;
  for(int h=1;h<100&&cnt<B;h+=2){
    for(int w=51;w<99&&cnt<B;w+=2){
        ans[h][w]='#';
        cnt++;
    }
  }
  cout<<100<<" "<<100<<endl;
  FOR(i,0,100)cout<<ans[i]<<endl;
}