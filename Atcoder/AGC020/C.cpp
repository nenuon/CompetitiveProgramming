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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
const int N = 2002 * 2002;
bitset<N> bs;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int sum = 0;
  bs.set(0);
  FOR(i,0,n) {
    int a; cin >> a;
    bs |= bs << a;
    sum += a;
  }
  FOR(i,(sum+1)/2,N) {
    if(bs[i]) {
      cout << i << endl;
      return 0;
    }
  }
}