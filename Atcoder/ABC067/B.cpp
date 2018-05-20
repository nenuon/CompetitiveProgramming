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

int main(){
  int N,K;
  cin>>N>>K;
  int l[N];
  FOR(i,0,N) cin>>l[i];
  sort(l,l+N);
  reverse(l,l+N);
  int ans = 0;
  FOR(i,0,K) ans += l[i];
  cout << ans << endl;
  return 0;
}
