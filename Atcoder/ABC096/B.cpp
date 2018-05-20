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
  int a[3];
  FOR(i,0,3)cin>>a[i];
  sort(a,a+3);
  int k;cin>>k;
  FOR(i,0,k){
    a[2]*=2;
  }
  int ans=0;
  FOR(i,0,3)ans+=a[i];
  cout<<ans<<endl;
}