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
#include <random>
#include <time.h>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
typedef pair<int, int> P;
// 宝石ごとの得点の配列を作る
// どの宝石を使わないのが良いかわかる
// 101点ではいもす法を使う
int main()
{
  int N, M; cin >> N >> M;
  ll imos[M+2]; FOR(i,0,M+2) imos[i] = 0;
  ll sum = 0;
  FOR(i,0,N) {
    int l, r, s;
    cin >> l >> r >> s;
    imos[l] += s;
    imos[r+1] -= s;
    sum += s;
  }
  FOR(i,0,M+1) imos[i+1] += imos[i];
  ll mn = 1e15;
  FOR(i,1,M+1) mn = min(mn, imos[i]);
  cout << sum - mn << endl;
  return 0;
}
