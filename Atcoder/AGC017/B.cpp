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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
typedef pair<ll, pair<int, int> > P;
ll llabs(ll x){
  return x > 0 ? x : -x;
}

int main(){
  ll N,A,B,C,D;
  cin>>N>>A>>B>>C>>D;
  bool ok = false;
  FOR(k,0,N){
    if(A+k*C-(N-1-k)*D<=B && B<=A+k*D-(N-k-1)*C){
      ok = true;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
