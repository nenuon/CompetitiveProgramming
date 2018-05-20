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
  int n;cin>>n;
  int a[n];
  FOR(i,0,n)cin>>a[i];
  sort(a,a+n);
  int ans=0;
  int d=2e9;
  FOR(i,0,n-1){
    if(d>abs(a[n-1]-a[i]-a[i])){
      ans=a[i];
      d=abs(a[n-1]-a[i]-a[i]);
    }
  }
  cout<<a[n-1]<<" "<<ans<<endl;
}