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
// 二次元累積和
// v は 1列目と1行目に0を追加した累積和を取りたいやつの配列
void integrate(vector<vector<int> >& v){
  const int n = 1010, m = 1010;
  FOR(i,0,n) FOR(j,0,m-1) v[i][j+1] += v[i][j]; // 横足して行く
  FOR(i,0,n-1) FOR(j,0,m) v[i+1][j] += v[i][j]; // 縦足して行く - > これで2次元の累積和になる！！！
}
int N, K;
int x[100005], y[100005];
string c[100005];
vector<vector<int> > vw_w(1010, vector<int>(1010, 0)), vw_b(1010, vector<int>(1010, 0)), vb_w(1010, vector<int>(1010, 0)), vb_b(1010, vector<int>(1010, 0));//wで希望w、wで希望b 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  FOR(i,0,N) cin >> x[i] >> y[i] >> c[i];
  //(0,0)->(k-1,k-1)をまず白
  FOR(i,0,N) {
    int X = x[i] % K + 1;
    int Y = y[i] % K + 1;
    bool isB = ((x[i] % (2 * K)) >= K) ^ ((y[i] % (2 * K)) >= K);
    if(isB) {
      if(c[i][0] == 'B') {
        vb_b[X][Y]++;
      } else {
        vb_w[X][Y]++;
      }
    } else {
      if(c[i][0] == 'W') {
        vw_w[X][Y]++;
      } else {
        vw_b[X][Y]++;
      }
    }
  }
  integrate(vw_w);
  integrate(vw_b);
  integrate(vb_w);
  integrate(vb_b);
  int ans = 0;
  FOR(i,1,K+1) {
    FOR(j,1,K+1) {
      int cnt = 0;
      // (0,0)->(i,j)を変更しない
      cnt += vw_w[i][j];
      cnt += vw_w[K][K] - vw_w[i][K] - vw_w[K][j] + vw_w[i][j];
      cnt += vw_b[K][j] - vw_b[i][j];
      cnt += vw_b[i][K] - vw_b[i][j];

      cnt += vb_b[i][j];
      cnt += vb_b[K][K] - vb_b[i][K] - vb_b[K][j] + vb_b[i][j];
      cnt += vb_w[K][j] - vb_w[i][j];
      cnt += vb_w[i][K] - vb_w[i][j];
      ans = max(ans, cnt);

      // 変更する
      cnt = 0;
      cnt += vw_b[i][j];
      cnt += vw_b[K][K] - vw_b[i][K] - vw_b[K][j] + vw_b[i][j];
      cnt += vw_w[K][j] - vw_w[i][j];
      cnt += vw_w[i][K] - vw_w[i][j];

      cnt += vb_w[i][j];
      cnt += vb_w[K][K] - vb_w[i][K] - vb_w[K][j] + vb_w[i][j];
      cnt += vb_b[K][j] - vb_b[i][j];
      cnt += vb_b[i][K] - vb_b[i][j];
      ans = max(ans, cnt);
    }
  }
  ans = max(ans, vw_w[K][K] + vb_b[K][K]);
  ans = max(ans, vw_b[K][K] + vb_w[K][K]);
  cout << ans << endl;
  return 0;
}