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
  ll K; cin >> K;
  ll N = 50;
  cout << N << endl;
  FOR(i,1,N+1) {
    if(i <= K % N) printf("%lld", K / N + 2 * N - 1 - K % N + 1);
    else printf("%lld", K / N + N - 1 - K % N);
    if(i<N) cout << " ";
  }
  cout << endl;
  return 0;
}
