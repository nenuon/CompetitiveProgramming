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
int toC(int A, int B, int C){
  if(!A&&!B)return 0;
  if(C&1)return toC(A>>1,B>>1,C>>1);
  else if(B&1)return toC(C>>1,B>>1,A>>1)+1+toC((A|B|C)>>1,0,0);
  else if(A&1)return toC(A>>1,B>>1,C>>1)+2*toC((A|B|C)>>1,0,0)+2;
  return 0;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  while(cin>>n>>m,n||m){
    int cup[3];// それぞれのトレイにあるカップの集合を表す
    CLR(cup);
    FOR(i,0,3){
      int t;cin>>t;
      FOR(j,0,t){
        int a;cin>>a;
        a--;
        cup[i]|=1<<a;
      }
    }
    //全てAカCにする
    int x=min(toC(cup[0],cup[1],cup[2]),toC(cup[2],cup[1],cup[0]));
    cout<<(x<=m?x:-1)<<endl;
  }
  return 0;
}
