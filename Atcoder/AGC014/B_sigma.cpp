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

int N, M;
const int NM = 100000;
vector<int> G[NM];
bool vis[NM];

vector<int> vc;

void dfs(int v){
    vis[v] = 1;
    for(int u:G[v]) if(!vis[u]){
        vc.push_back(u);
        dfs(u);
        break;
    }
}

int main(){
    cin >> N >> M;
    FOR(i, 0, M){
        int x, y;
        cin>>x>>y;
        x--;y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> ans;
    dfs(0);
    reverse(vc.begin(), vc.end());
    for(int v:vc) ans.push_back(v);
    vc.clear();
    dfs(0);
    ans.push_back(0);
    for(int v:vc) ans.push_back(v);
    cout << ans.size() << endl;
    for(int v:ans) cout << v+1 << " ";
    puts("");
}
