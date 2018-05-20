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
int N;
bool check(vector<string> vs, int x){
  vector<string> vs2(vs.size());
  FOR(i,0,N){
    string s="";
    FOR(j,0,N){
      int k=(j+x)%N;
      s+=vs[i][k];
    }
    vs2[i]=s;
  }
  FOR(i,0,N){
    FOR(j,0,N){
      if(vs2[i][j]!=vs2[j][i]){
        return false;
      }
    }
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>N;
  vector<string> vs(N);
  FOR(i,0,N)cin>>vs[i];
  ll ans=0;
  FOR(i,0,N){
    if(check(vs,i))ans++;
  }
  cout<<ans*N<<endl;
}