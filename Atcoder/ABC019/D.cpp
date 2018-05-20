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
  int N; cin >> N;
  int dist = 0, v = 1;
  FOR(i,2,N+1) {
    cout << "? 1 " << i << endl;
    int in; cin >> in;
    if(dist < in) {
      v = i;
      dist = in;
    }
  }
  dist = 0;
  FOR(i,1,N+1) {
    if(i == v) continue;
    cout << "? " << v << " " << i << endl;
    int in; cin >> in;
    dist = max(dist, in);
  }
  cout << "! " << dist << '\n';
  return 0;
}
