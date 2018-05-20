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
const double EPS = 1e-10;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;cin>>N;
  int x[N],y[N];
  FOR(i,0,N)cin>>x[i]>>y[i];
  //鈍角三角形と直角三角形の個数を求める
  int don=0,tyo=0,ei=0;
  FOR(i,0,N){
    //i周りの点の角度を求める
    vector<double> deg;
    FOR(j,0,N){
      if(i==j)continue;
      deg.push_back(atan2(y[j]-y[i],x[j]-x[i]));
    }
    sort(deg.begin(),deg.end());
    FOR(j,0,N-1)deg.push_back(deg[j]+2*M_PI);
    FOR(j,0,N-1){
      int x=lower_bound(deg.begin(),deg.end(),deg[j]+M_PI/2-EPS)-deg.begin();
      int y=upper_bound(deg.begin(),deg.end(),deg[j]+M_PI/2+EPS)-deg.begin();
      int z=lower_bound(deg.begin(),deg.end(),deg[j]+M_PI)-deg.begin();
      tyo+=y-x;
      don+=z-y;
    }
  }
  cout<<(ll)N*(ll)(N-1)*(N-2)/6-tyo-don<<" "<<tyo<<" "<<don<<endl;
  return 0;
}