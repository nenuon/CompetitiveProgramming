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
int main(){
  cin>>N;
  ll a[N],b[N];
  FOR(i,0,N)cin>>a[i];
  FOR(i,0,N)cin>>b[i];
  ll ans=0;
  FOR(i,0,30){
    ll T=1<<i;
    ll cnt=0;
    vector<int> v(N);
    FOR(j,0,N)v[j]=b[j]%(2*T);
    sort(v.begin(),v.end());
    FOR(j,0,N){
      ll aa=a[j]%(2*T);
      cnt+=lower_bound(v.begin(),v.end(),2*T-aa)-lower_bound(v.begin(),v.end(),T-aa);
      cnt+=lower_bound(v.begin(),v.end(),4*T-aa)-lower_bound(v.begin(),v.end(),3*T-aa);
    }
    if(cnt%2)ans+=T;
  }
  cout<<ans<<endl;
  return 0;
}