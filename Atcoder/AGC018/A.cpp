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
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  bool ok = false;
  FOR(i,0,N) {
    cin >> A[i];
    if(A[i] == K) ok = true;
  }
  if(ok) {
    cout << "POSSIBLE" << endl;
    return 0;
  }
  sort(A.begin(), A.endl());
  if(K > A[N-1]) {
    cout << "INPOSSIBLE" << endl;
    return 0;
  }
  FOR(i,0,N-1) {
    A.push_back(A[i+1]-A[i]);
  }
  sort(A.begin(), A.endl());

}
