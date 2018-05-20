
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
bool ok(ll k){
  if(R-k<0||B-k<0)return false;
  return (R-k)/(x-1)+(B-k)/(y-1)>=k;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>R>>B>>x>>y;
  ll r=2e18,l=-1;
  while(r-l>1){
    ll m=(r+l)/2;
    if(ok(m))l=m;
    else r=m;
  }
  cout<<l<<endl;
}