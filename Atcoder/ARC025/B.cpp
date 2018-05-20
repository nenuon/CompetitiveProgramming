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
// 二次元累積和
// v は 1列目と1行目に0を追加した累積和を取りたいやつの配列
void integrate(vector<vector<int> >& v){
    const int n = v.size(), m = v[0].size();
    FOR(i,0,n) FOR(j,0,m-1) v[i][j+1] += v[i][j]; // 横足して行く
    FOR(i,0,n-1) FOR(j,0,m) v[i+1][j] += v[i][j]; // 縦足して行く - > これで2次元の累積和になる！！！
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W; cin >> H >> W;
  vector<vector<int> > black(H + 1, vector<int>(W + 1, 0));
  vector<vector<int> > white(H + 1, vector<int>(W + 1, 0));
  FOR(y,1,H+1) {
    FOR(x,1,W+1) {
      int in; cin >> in;
      if((y+x)%2==0) black[y][x] = in;
      else white[y][x] = in;
    }
  }
  integrate(black);
  integrate(white);
  int ans = 0;
  FOR(y,1,H+1) {
    FOR(x,1,W+1) {
      FOR(Y,y,H+1) {
        FOR(X,x,W+1) {
          int b = black[Y][X] - black[Y][x-1] - black[y-1][X] + black[y-1][x-1];
          int w = white[Y][X] - white[Y][x-1] - white[y-1][X] + white[y-1][x-1];
          if(b == w) ans = max(ans, (X - x + 1) * (Y - y + 1));
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
