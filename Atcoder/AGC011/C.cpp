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
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

//Union-Find
int par[100001], rank[100001], h[100001];
void init(){FOR(i, 0, 100001) par[i]=i,rank[i]=0,h[i]=0;}
int find(int x){return (par[x]==x)?x:(par[x]=find(par[x]));}
void union(int x, int y){
    x = find(x);y = find(y);
    if(x==y) return;
    if(rank[x]<rank[y]) par[x]=y;
    else {par[y]=x;if(rank[x]==rank[y]) rank[x]++;}
}
bool same(int x, int y){return find(x)==find(y);}

vector<int> v[111111];//頂点?
bool u[111111][2];//[頂点][2次元グラフにした時のx座標かy座標か?]
void dfs(int x, int t, int p){
    if(u[x][t]) return;
    u[x][t] = 1;//処理したら1
    //頂点xに繋がっている頂点について
    FOR(i, 0, v[x].size()){
        int y = v[x][i];
        if(y == p) continue;//自己
        dfs(y, t^1, x);
    }
}

int main(){
    init();
    ll n, m;//頂点の数、辺の数
    cin >> n >> m;
    //辺の情報入力
    FOR(i, 0, m){
        int x, y;
        cin >> x >> y;
        x--;y--;
        v[x].push_back(y);//頂点xに頂点yが繋がっている
        v[y].push_back(x);//頂点yに頂点xが繋がっている
        unite(x,y);//繋がっている頂点を同じグループとする
    }
    //各頂点について
    FOR(i, 0, n){
        if(u[i][0] || u[i][1]) continue;
        dfs(i, 0, -1);
    }
}
