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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, M; cin >> N >> M;
  ll one = 1900 * M + (N - M) * 100;
  double p = 0;
  int t = 1; // t回目で成功する
  double sum = 0;
  while((1.0-p)>1e-9) {
    sum += pow(1.0 - 1.0 / pow(2, M) , t - 1) / pow(2, M) * one * t;
    p += pow(1.0 - 1.0 / pow(2, M) , t - 1) / pow(2, M);
    t++;
  }
  cout << ceil(sum) << endl;
  return 0;
}