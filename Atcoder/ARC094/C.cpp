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
  int v[3];
  FOR(i,0,3)cin>>v[i];
  sort(v,v+3);
  int ans=0;
  ans=v[2]-v[0]+v[2]-v[1];
  if(ans%2==1){
    ans=v[2]-v[0]+v[2]-v[1]+3;
  }
  cout<<ans/2<<endl;
  

}