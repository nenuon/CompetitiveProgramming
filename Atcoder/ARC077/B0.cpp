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
const ll mod = 1000000007;
int main(){
  int n;
  cin >> n;
  if(n==1){
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }
  int a[n+1];
  FOR(i,0,n+1) a[i] = 0;
  int p;
  FOR(i,0,n) {
    int in;
    cin >> in;
    a[in]++;
    if(a[in] == 2) p = i;
  }
  ll d[n+2];
  FOR(i,0,n+1){
    if()
  }
  return 0;
}
