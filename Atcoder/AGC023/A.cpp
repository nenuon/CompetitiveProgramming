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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;cin>>N;
  ll sum=0;
  map<ll, ll> MAP;
  MAP[0]++;
  FOR(i,0,N){
    ll A;cin>>A;
    sum += A;
    MAP[sum]++;
  }
  ll ans=0;
  for(auto m : MAP){
    ans += m.second*(m.second-1)/2;
  }
  cout<<ans<<endl;
  return 0;
}