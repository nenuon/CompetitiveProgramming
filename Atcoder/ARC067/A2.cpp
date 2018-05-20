
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
const int mod=1e9+7;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;cin>>N;
  int num[N];
  FOR(i,0,N)num[i]=i+1;
  map<int,int> MAP;
  FOR(i,0,N){
    int x=num[i];
    FOR(j,2,sqrt(num[i])+1){
      while(x%j==0){
        MAP[j]++;
        x/=j;
      }
    }
    if(x>1)MAP[x]++;
  }
  ll ans=1;
  for(auto m : MAP){
    ans*=m.second+1;
    ans%=mod;
  }
  cout<<ans<<endl;
}