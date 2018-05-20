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
// 重ねられるなら差が小さいところに
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int box[N]; FOR(i,0,N) cin >> box[i];
  vector<int> bring;
  bring.push_back(box[0]);
  FOR(i,1,N) {
    int d = 1e9, k = -1;
    FOR(j,0,bring.size()) {
      if(bring[j] >= box[i] && d >= bring[j] - box[i]) {
        d = bring[j] - box[i];
        k = j;
      }
    }
    if(k == -1) bring.push_back(box[i]);
    else bring[k] = box[i];
  }
  cout << (int)bring.size() << endl;
  return 0;
}
