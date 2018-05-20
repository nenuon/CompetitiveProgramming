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
  ll N;
  cin >> N;
  ll a[N];
  FOR(i,0,N) cin >> a[i];
  //sort(a.rbegin(), a.rend());
  ll need = 0;
  ll nd[N];
  FOR(i,0,N) nd[i] = 0;
  while(1) {
    ll cnt = 0;
    bool ok = true;
    FOR(i,0,N) {
      nd[i] = a[i] / N;
      a[i] -= nd[i] * N;
      need += nd[i];
      cnt += nd[i];
    }
    FOR(i,0,N) {
      a[i] += cnt - nd[i];
      if(a[i] >= N) ok = false;
    }
    if(ok) {
      cout << need << endl;
      return 0;
    }
  }
  return 0;
}
