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

//選ばれたらtrue
//一個点を選んで端っこまで見ていく
//最初の点から二方向

int N, M;
vector<int> G[100001];
bool isUsed[100001];
vector<int> v;
vector<int> ans1, ans2;

void dfs(int x){
    isUsed[x] = true;
    FOR(i, 0, G[x].size()){
        if(isUsed[G[x][i]]) continue;
        dfs(G[x][i]);
        break;
    }
    v.push_back(x);
    return;
}

int main(){
    cin >> N >> M;
    int a, b;
    FOR(i, 0, M){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    FOR(i, 0, N) isUsed[i] = false;
    dfs(a);
    int len = v.size();
    ans1 = v;
    if(G[a].size()==1){
        cout << len << endl;
        FOR(i, 0, ans1.size()){
            if(i) cout << " ";
            cout << ans1[i];
        }
        cout << endl;
        return 0;
    }
    v.clear();v.shrink_to_fit();
    dfs(a);
    if(v.size()<=1){
        cout << len << endl;
        FOR(i, 0, ans1.size()){
            if(i) cout << " ";
            cout << ans1[i];
        }
        cout << endl;
        return 0;
    }
    reverse(v.begin(), v.end());
    len += v.size() -1;
    ans2 = v;
    cout << len << endl;
    FOR(i, 0, ans1.size()){
        if(i) cout << " ";
        cout << ans1[i];
    }
    cout << " ";
    FOR(i, 1, ans2.size()){
        if(i>1) cout << " ";
        cout << ans2[i];
    }
    cout << endl;
}
