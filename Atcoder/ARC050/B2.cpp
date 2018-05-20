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
ll R,B,x,y;
ll calc(ll K){
  if(R-K<0||B-K<0)return false;
  return ((R-K)/(x-1)+(B-K)/(y-1))>=K;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>R>>B>>x>>y;
  ll l=0,r=1e18;
  while(r-l>1){
    ll m=(r+l)/2;
    if(calc(m))l=m;
    else r=m;
  }
  cout<<l<<endl;
  return 0;
}