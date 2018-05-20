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
  int N; cin >> N;
  vector<int> rate(N+2);
  rate[N] = -1;
  rate[N+1] = 1e9;
  int data[100005][4]; CLR(data);
  int R[N], H[N];
  FOR(i,0,N) {
    cin >> R[i] >> H[i];
    data[R[i]][H[i]]++;
    rate[i] = R[i];
  }
  sort(rate.begin(), rate.end());
  FOR(i,0,N) {
    int win = 0, lose = 0, draw = 0;
    win += lower_bound(rate.begin(), rate.end(), R[i]) - rate.begin() - 1;
    lose += N - (upper_bound(rate.begin(), rate.end(), R[i]) - rate.begin()) + 1;
    // レート同じ人
    if(H[i] == 1) {
      win += data[R[i]][2];
      lose += data[R[i]][3];
      draw += data[R[i]][1]-1;
    } else if(H[i] == 2) {
      win += data[R[i]][3];
      lose += data[R[i]][1];
      draw += data[R[i]][2]-1;
    } else {
      win += data[R[i]][1];
      lose += data[R[i]][2];
      draw += data[R[i]][3]-1;
    }
    cout << win << " " << lose << " " << draw << endl;
  }
  return 0;
}
