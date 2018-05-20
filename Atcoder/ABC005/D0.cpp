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
int N;
vector<vector<int> > v;
// 二次元累積和
// v は 1列目と1行目に0を追加した累積和を取りたいやつの配列
void integrate(){
    const int n = v.size(), m = v[0].size();
    FOR(i,0,n) FOR(j,0,m-1) v[i][j+1] += v[i][j]; // 横足して行く
    FOR(i,0,n-1) FOR(j,0,m) v[i+1][j] += v[i][j]; // 縦足して行く - > これで2次元の累積和になる！！！
}
// (x, y) 左上の座標, (w, h) 幅
int calc(int x, int y, int w, int h) {
  if(w + x - 1 > N || h + y - 1 > N) return 0;
  return v[h+y-1][w+x-1] - v[h+y-1][x-1] - v[y-1][w+x-1] + v[y-1][x-1];
}
int main()
{
  cin >> N;
  v.resize(N+1);
  FOR(i,0,N+1) {
    FOR(j,0,N+1) {
      if(i == 0) v[i].push_back(0);
      else if(j == 0) v[i].push_back(0);
      else {
        int in; cin >> in;
        v[i].push_back(in);
      }
    }
  }
  integrate();
  int mx[N*N+1];
  FOR(i,0,N*N+1) mx[i] = 0;
  FOR(p,1,N*N+1){
    for(int h = N; h >= 1; h--) {
      int w = min(p / h, N);
      FOR(y,1,N+1) {
        FOR(x,1,N+1) {
          mx[p] = max(mx[p], calc(x,y,w,h));
        }
      }
    }
  }
  FOR(i,0,N*N) mx[i+1] = max(mx[i+1], mx[i]);
  int Q; cin >> Q;
  FOR(i,0,Q) {
    int P; cin >> P;
    cout << mx[P] << endl;
  }
  return 0;
}
