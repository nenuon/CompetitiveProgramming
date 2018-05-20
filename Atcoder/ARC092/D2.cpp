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
ll a[200005],b[200005];
ll two[30];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;cin>>N;
  FOR(i,0,N)cin>>a[i];
  FOR(i,0,N)cin>>b[i];
  // 2^kの位が1となる個数を数える
  two[0]=1;
  FOR(i,1,30)two[i]=two[i-1]*2;
  ll ans = 0;
  FOR(k,0,29){
    // aiと足して1になるbjの個数を一気に求める
    // 2^(k+1)以上のくらいは意味ないので2^(k+1)で割っておく
    vector<ll> bb(N);
    FOR(i,0,N)bb[i]=b[i]%two[k+1];
    sort(bb.begin(),bb.end());
    ll cnt=0;
    FOR(i,0,N){
      int aa=a[i]%two[k+1];
      cnt+=lower_bound(bb.begin(),bb.end(),2*two[k]-aa)-lower_bound(bb.begin(),bb.end(),two[k]-aa);
      cnt+=lower_bound(bb.begin(),bb.end(),4*two[k]-1-aa)-lower_bound(bb.begin(),bb.end(),3*two[k]-aa);
    }
    if(cnt%2)ans+=two[k];
  }
  cout<<ans<<endl;
  return 0;
}