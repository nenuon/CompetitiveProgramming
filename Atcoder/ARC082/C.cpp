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
  int num[100005]; CLR(num);
  FOR(i,0,N) {
    int in; cin >> in;
    num[in]++;
    if(in > 0) num[in-1]++;
    num[in+1]++;
  }
  int ans = 0, mx = 0;
  FOR(i,0,100005) {
    if(mx < num[i]) {
      mx = num[i];
      ans = i;
    }
  }
  cout << num[ans] << endl;
  return 0;
}
