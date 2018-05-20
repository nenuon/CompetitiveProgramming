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
  int A,B,C;cin>>A>>B>>C;
  int X,Y;cin>>X>>Y;
  int ans=1e9;
  for(int i=0;i<200005;i+=2){
    int tmp=0;
    int x=X,y=Y;
    x-=i/2;
    y-=i/2;
    tmp+=i*C;
    if(x>0)tmp+=A*x;
    if(y>0)tmp+=B*y;
    ans=min(ans,tmp);
  }
  cout<<ans<<endl;
}