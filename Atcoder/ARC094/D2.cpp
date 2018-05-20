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
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
vector<PP> C;
ll ans,nokori;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;cin>>N;
  C.resize(N);
  bool end=true;
  FOR(i,0,N){
    int A,B;
    cin>>A>>B;
    C[i]=PP(A-B,P(B,A));
    if(A!=B)end=false;
  }
  if(end){
    cout<<0<<endl;
    return 0;
  }
  sort(C.rbegin(),C.rend());
  FOR(i,0,N){
    int A=C[i].second.second;
    int B=C[i].second.first;
    if(A<=B){
      ans+=B;
      nokori=B-A;
    }
  }
  FOR(i,0,N){
    int A=C[i].second.second;
    int B=C[i].second.first;
    if(A>B){
      if(A-B+1<=nokori){
        ans+=B;
        nokori-=A-B+1;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}