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

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int N,M;
bool isUsed[8];
bool g[8][8];

int dfs(int x, int nokori){
    if(nokori==0) return 1;
    int ret = 0;
    isUsed[x] = true;
    //次
    FOR(i, 0, N){
        if(g[x][i] && !isUsed[i]){
            //trueにしとく
            isUsed[i] = true;
            ret += dfs(i, nokori-1);
            //調べ終わったらfalseにしとく
            isUsed[i] = false;
        }
    }
    return ret;
}

int main(){
    cin>>N>>M;
    FOR(i, 0, 8) FOR(j, 0, 8) g[i][j] = false;
    FOR(i, 0, 8) isUsed[i] = false;
    FOR(i, 0, M){
        int a, b;
        cin>>a>>b;
        a--;b--;
        g[a][b] = g[b][a] = true;
    }
    cout << dfs(0, N-1) << endl;
}
