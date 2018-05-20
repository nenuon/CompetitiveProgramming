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
  int A[N+2];FOR(i,1,N+1)cin>>A[i];
  A[0]=A[N+1]=0;
  int mx=0;
  FOR(i,0,N+1){
    mx+=abs(A[i+1]-A[i]);
  }
  FOR(i,0,N){
    cout<<mx-abs(A[i+1]-A[i])-abs(A[i+2]-A[i+1])+abs(A[i+2]-A[i])<<endl;
  }
}