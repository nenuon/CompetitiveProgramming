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
typedef pair<ll, ll> P;
const int mod=1e9+7;
map<P,ll> MAP;
ll f(ll T1, ll T2) {
  if(MAP.count(P(T1,T2)))return MAP[P(T1,T2)];
  if(T1<0||T2<0)return 0;
  if(T1==0&&T2==0)return 1;
  return MAP[P(T1,T2)]=(f(T1/2,T2/2)+(T1>=2?f((T1-2)/2,T2/2):0)+(T1>=1&&T2>=1?f((T1-1)/2,(T2-1)/2):0))%mod;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N;cin>>N;
  cout<<f(N,N)<<endl;
}