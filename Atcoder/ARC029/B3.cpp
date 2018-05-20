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
  int A,B;cin>>A>>B;
  int N;cin>>N;
  if(A<B)swap(A,B);
  FOR(i,0,N){
    int C,D;cin>>C>>D;
    if(C<D)swap(C,D);
    if(A<C&&B<D){
      cout<<"YES"<<endl;
      continue;
    }
    if(B>=D){
      cout<<"NO"<<endl;
      continue;
    }
    double t1=0.0,t2=M_PI/2;
    // できるだけ横にする
    FOR(j,0,100){
      double m=(t1+t2)/2;
      double yoko=A*cos(m)+B*sin(m);
      //cout<<yoko<<endl;
      if(yoko>D){
        t1=m;
      }else{
        t2=m;
      }
    }
    double tate=A*sin((t1+t2)/2)+B*cos((t1+t2)/2);
    //cout<<tate<<endl;
    cout<<(tate<C?"YES":"NO")<<endl;
  }
  return 0;
}