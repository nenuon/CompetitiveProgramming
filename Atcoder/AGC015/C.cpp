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

#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

typedef long long ll;

// 二次元累積和
// 森について -> 頂点の数 - 辺の数 = 連結成分の個数
// 頂点の数と辺の数を累積しておく
// 求めたい場所については累積和の足し算引き算でO(1)

// 頂点の数と辺の数は深さ優先全探索でok???

int N, M, Q;
vector<string> vs;
int tyoten[2020][2020];
int hen[2020][2020];

// 2次元累積和
void init(){
    // 左上
    tyoten[0][0] = (vs[0][0] == '1' ? 1 : 0);
    hen[0][0] = 0;

    // x 方向
    FOR(x,1,M){
        if(vs[0][x]=='1') tyoten[0][x] = tyoten[0][x-1] + 1;
        else tyoten[0][x] = tyoten[0][x-1];
        if(vs[0][x-1] == '1' && vs[0][x] == '1') hen[0][x] = hen[0][x-1] + 1;
        else hen[0][x] = hen[0][x-1];
    }

    // y 方向
    FOR(y,1,N){
        if(vs[y][0]=='1') tyoten[y][0] = tyoten[y-1][0] + 1;
        else tyoten[y][0] = tyoten[y-1][0];
        if(vs[y-1][0] == '1' && vs[y][0] == '1') hen[y][0] = hen[y-1][0] + 1;
        else hen[y][0] = hen[y-1][0];
    }

    // xy方向
    FOR(y,1,N){
        FOR(x,1,M){
            tyoten[y][x] = tyoten[y-1][x] + tyoten[y][x-1] - tyoten[y-1][x-1];
            if(vs[y][x]=='1') tyoten[y][x]++;
            hen[y][x] = hen[y-1][x] + hen[y][x-1] - hen[y-1][x-1];
            if(vs[y][x] == '1'){
                if(vs[y-1][x] == '1') hen[y][x]++;
                if(vs[y][x-1] == '1') hen[y][x]++;
            }
        }
    }
}

int calc(int x1, int y1, int x2, int y2){
    int t, h; // 頂点の数、辺の数
    t = tyoten[y2][x2];
    h = hen[y2][x2];
    if(x1>0) t -= tyoten[y2][x1-1], h -= hen[y2][x1-1];
    if(y1>0) t -= tyoten[y1-1][x2], h -= hen[y1-1][x2];
    if(x1>0 && y1>0) t += tyoten[y1-1][x1-1], h += hen[y1-1][x1-1];
    return t - h;
}

int main(){
    cin >> N >> M >> Q;
    vs.resize(N);
    FOR(i,0,N) cin >> vs[i];
    init();
    FOR(y,0,N){
        FOR(x,0,M){
            cout << hen[y][x] << " ";
        }
        cout << endl;
    }
    FOR(q,0,Q){
        int x1, y1, x2, y2; // x->行 y->列 に注意
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;x2--;y1--;y2--;
        cout << calc(y1,x1,y2,x2) << endl;
    }
    return 0;
}
