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

void integrate(vector<vector<int> >& v){
    const int n = v.size(), m = v[0].size();
    FOR(i,0,n) FOR(j,0,m-1) v[i][j+1] += v[i][j]; // 横足して行く
    FOR(i,0,n-1) FOR(j,0,m) v[i+1][j] += v[i][j]; // 縦足して行く - > これで2次元の累積和になる！！！
}

int query(const vector<vector<int> >& v, int x1, int y1, int x2, int y2){
    return v[y1][x1] - v[y1][x2] - v[y2][x1] + v[y2][x2];
}

int main(){
    ios_base::sync_with_stdio(false);
    int n,m,q;
    cin>>n>>m>>q;
    vector<string> f(n);
    FOR(i,0,n) cin >> f[i];
    vector<vector<int> > c(n+1, vector<int>(m+1)); // 頂点数
    vector<vector<int> > h(n+1, vector<int>(m)); // 横方向の辺の数？ horizontal
    vector<vector<int> > v(n, vector<int>(m+1)); // 縦方向の辺の数？ vertical

    // とりあえず値入れる
    FOR(i,0,n) FOR(j,0,m) c[i+1][j+1] = f[i][j] - '0';
    FOR(i,0,n) FOR(j,0,m-1) if(f[i][j] == '1' && f[i][j+1] == '1') h[i+1][j+1] = 1;
    FOR(i,0,n-1) FOR(j,0,m) if(f[i][j] == '1' && f[i+1][j] == '1') v[i+1][j+1] = 1;

    integrate(c);
    integrate(h);
    integrate(v);

    while(q--){
        int x1,y1,x2,y2;
        cin>>y1>>x1>>y2>>x2;
        --x1;--y1;
        const int cs = query(c, x1, y1, x2, y2);
        const int hs = query(h, x1, y1, x2 - 1, y2); // 横の辺は調べたい区間のx-1にしとく
        const int vs = query(v, x1, y1, x2, y2 - 1); // 縦の辺は調べたい区間のy-1にしとく
        cout << cs - hs - vs << endl;
    }
    return 0;
}
