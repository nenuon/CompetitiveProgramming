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
#define FOR(I,A,B) for(long long I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
ll f(ll b, ll n){
  if(n<b)return n;
  else return f(b,n/b)+n%b;
}
  int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,s;
  cin>>n>>s;
  if(n==s){
    cout<<n+1<<endl;
    return 0;
  }
  // b<sqrt(n)
  FOR(b,2,sqrt(n)+1){
    //cout<<b<<" "<<f(b,n)<<endl;
    if(f(b,n)==s){
      cout<<b<<endl;
      return 0;
    }
  }
  ll ans = 1e18;
  // b>sqrt(n)
  FOR(p,1,sqrt(n)+1){
    ll q=s-p;
    if((n-q)%p==0){
      ll b=(n-q)/p;
      if(q>=0&&q<b&&b>1&&f(b,n)==s) ans=min(ans,b);
    }
  }
  cout<<(ans==1e18?-1:ans)<<endl;
  return 0;
}