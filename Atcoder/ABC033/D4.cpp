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
  int don=0,tyo=0;
  // i中心
  FOR(i,0,N){
    vector<double> v;
    FOR(j,0,N){
      if(i==j)continue;
      double th = atan2(y[j]-y[i],x[j]-x[i]);
      v.push_back(th);
      v.push_back(th+M_PI*2);
    }
    sort(v.begin(),v.end());
    FOR(j,0,N-1){
      tyo += lower_bound(v.begin(),v.end(),M_PI/2+v[j]+EPS)-lower_bound(v.begin(),v.end(),M_PI/2+v[j]-EPS);
      don += lower_bound(v.begin(),v.end(),M_PI+v[j])-lower_bound(v.begin(),v.end(),M_PI/2+v[j]+EPS);
    }
  }
  cout<<(ll)N*(N-1)*(N-2)/6-tyo-don<<" "<<tyo<<" "<<don<<endl;
}