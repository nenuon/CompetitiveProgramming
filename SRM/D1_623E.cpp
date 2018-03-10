#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
using namespace std;
// 二次元累積和
// v は 1列目と1行目に0を追加した累積和を取りたいやつの配列
void integrate(vector<vector<int> >& v){
    const int n = v.size(), m = v[0].size();
    FOR(i,0,n) FOR(j,0,m-1) v[i][j+1] += v[i][j]; // 横足して行く
    FOR(i,0,n-1) FOR(j,0,m) v[i+1][j] += v[i][j]; // 縦足して行く - > これで2次元の累積和になる！！！
}
class UniformBoard {
    public:
    int getBoard(vector<string> board, int K) {
        int n = board[0].size();
        vector<vector<int> > p(n+1, vector<int>(n+1, 0));
        vector<vector<int> > dot(n+1, vector<int>(n+1, 0));
        bool canMove = false;
        int numA = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'P') p[i+1][j+1] = 1;
                if(board[i][j] == 'A') numA++;
                if(board[i][j] == '.') {
                    dot[i+1][j+1] = 1;
                    canMove = true;
                }
            }
        }
        integrate(p);
        integrate(dot);
        int ans = 0;
        // 全探索
        for(int y1 = 1; y1 <= n; y1++) {
            for(int x1 = 1; x1 <= n; x1++) {
                for(int y2 = y1; y2 <= n; y2++) {
                    for(int x2 = x1; x2 <= n; x2++) {
                        int numP, numDot;
                        numP = p[y2][x2] - p[y2][x1-1] - p[y1-1][x2] + p[y1-1][x1-1];
                        numDot = dot[y2][x2] - dot[y2][x1-1] - dot[y1-1][x2] + dot[y1-1][x1-1];
                        if(numP == 0 && numDot == 0) ans = max(ans, (y2-y1+1)*(x2-x1+1));
                        if(2*numP+numDot <= K && canMove && numA >= (y2-y1+1)*(x2-x1+1)) ans = max(ans, (y2-y1+1)*(x2-x1+1));
                    }
                }
            }
        }
        return ans;
    }
};
