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

//方針
//dfsで
//訪れていたらused=true
//繋がってるところ全部再帰する
//その時のused=falseならok

int N,M;
bool used[64];
bool to[8][8];

int  dfs(int n, int nokori){
    used[n] = true;
    if(nokori==0) return 1;
    int ret = 0;
    FOR(i, 0, N){
        if(!to[n][i]) continue;
        if(to[n][i] && !used[i]){
            ret += dfs(i, nokori-1);
            used[i] = false;
        }
    }
    return ret;
}

int main(){
    FOR(i, 0, 8) FOR(j, 0, 8) to[i][j] = false;
    FOR(i, 0, 64) used[i] = false;
    cin>>N>>M;
    FOR(i, 0, M){
        int a,b;cin>>a>>b;
        a--;b--;
        to[a][b] = to[b][a] = true;
    }
    cout << dfs(0, N-1) << endl;
}
