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
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int N;
char C[4040];
int A[4040];
int dp[2020][2020]; // 白1~i、黒1~jまで目標を達成するのに必要な最小のスワップ回数
int pos[2][2020]; // W==1,B==0の数jの位置
vector<vector<int> > crsW(2002, vector<int>(4040, 0)); // 0~j番目で数がi以上
vector<vector<int> >  crsB(2002, vector<int>(4040, 0)); // 0~j番目で数がi以上
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
  cin>>N;
  FOR(i,0,2*N){
    cin>>C[i]>>A[i];
    pos[C[i]=='W'][A[i]] = i + 1;
    if(C[i] == 'W') crsW[A[i]][i+1]++;
    else crsB[A[i]][i+1]++;
  }
  integrate(crsW);
  integrate(crsB);
  FOR(i,0,2020) FOR(j,0,2020) dp[i][j] = 1e9;
  dp[0][0] = 0;
  FOR(i,0,N+1){
    FOR(j,0,N+1){
      // 白のi+1を持ってくる
      int cross = 0;
      // W
      cross = crsW[N][pos[1][i+1]] - crsW[i+1][pos[1][i+1]];
      // B
      cross += crsB[N][pos[1][i+1]] - crsB[j][pos[1][i+1]];
      dp[i+1][j] = min(dp[i+1][j], dp[i][j] + cross);
      // 黒のj+1を持ってくる
      // W
      cross = crsW[N][pos[0][j+1]] - crsW[i][pos[0][j+1]];
      // B
      cross += crsB[N][pos[0][j+1]] - crsB[j+1][pos[0][j+1]];
      dp[i][j+1] = min(dp[i][j+1], dp[i][j] + cross);
    }
  }
  cout<<dp[N][N]<<endl;
}