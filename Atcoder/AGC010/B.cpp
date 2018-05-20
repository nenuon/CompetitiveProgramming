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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  ll sum = 0;
  ll A[N], sa[N];
  FOR(i,0,N) {
    cin >> A[i];
    sum += A[i];
  }
  if(sum % (N * (N + 1) / 2) != 0) {
    cout << "NO" << endl;
    return 0;
  }
  ll x = sum / (N * (N + 1) / 2);
  FOR(i,0,N) {
    sa[i] = A[(i + 1) % N] - A[i];
  }
  ll ksum = 0;
  FOR(i,0,N) {
    if((x - sa[i]) % N != 0 || (x - sa[i]) < 0) {
      cout << "NO" << endl;
      return 0;
    }
    ksum += (x - sa[i]) / N;
  }
  if(x == ksum) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}