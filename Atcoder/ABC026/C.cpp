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

//直属の部下を保存しておく[上司id][部下id]
//dfsで直属の部下を見て行く
//部下がいない場合return 1

vector<vector<int> > vv(20);

int dfs(int buka){
    int len = vv[buka].size();
    if(len==0) return 1;
    int MIN = 99999999, MAX = 0, ret;
    FOR(i, 0, len){
        MIN = min(MIN, dfs(vv[buka][i]));
        MAX = max(MAX, dfs(vv[buka][i]));
    }
    ret = MAX + MIN + 1;
    return ret;
}

int main(){
    int N;
    cin >> N;
    N--;
    FOR(i,1,N+1){
        int b;
        cin >> b;
        b--;
        vv[b].push_back(i);
    }
    ll ans = 0;
    ans += dfs(0);
    cout << ans << endl;
}
