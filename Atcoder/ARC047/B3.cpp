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
int N;
vector<int> x,y,X,Y;
bool check(int cx, int cy){
  // 元の座標に戻す
  int px=(cx+cy)/2;
  int py=(cx-cy)/2;
  int d=abs(x[0]-px)+abs(y[0]-py);
  FOR(i,1,N){
    if(abs(x[i]-px)+abs(y[i]-py)!=d)return false;
  }
  cout<<px<<" "<<py<<endl;
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>N;
  x.resize(N);
  y.resize(N);
  X.resize(N);
  Y.resize(N);
  FOR(i,0,N)cin>>x[i]>>y[i];
  FOR(i,0,N){
    X[i]=x[i]+y[i];
    Y[i]=x[i]-y[i];
  }
  sort(X.begin(),X.end());
  sort(Y.begin(),Y.end());
  int D=max(X[N-1]-X[0],Y[N-1]-Y[0]);
  if(check(X[0]+D/2,Y[0]+D/2))return 0;
  if(check(X[N-1]-D/2,Y[0]+D/2))return 0;
  if(check(X[0]+D/2,Y[N-1]-D/2))return 0;
  if(check(X[N-1]-D/2,Y[N-1]-D/2))return 0;
}