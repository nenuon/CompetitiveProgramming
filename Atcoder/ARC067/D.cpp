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

int main()
{
  int N; cin >> N;
  ll A, B;
  cin >> A >> B;
  ll X[N];
  FOR(i,0,N) cin>>X[i];
  ll ans = 0;
  FOR(i,0,N-1) {
    ans += min((X[i+1]-X[i])*A, B);
  }
  cout << ans << endl;
  return 0;
}
