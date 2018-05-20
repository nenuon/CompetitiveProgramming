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

#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

int N;
vector<vector<int> > G;

int dfs(int x, int pr){
    int ret = 0;
    for(auto next : G[x]){
        if(next==pr) continue;
        ret += dfs(next, x);
    }

    if(ret>=2){
        cout << "First" << endl;
        exit(0);
    }
    if(ret==0) return 1;
    return 0;
}

int main(){
    cin >> N;
    G.resize(N);
    FOR(i,0,N-1){
        int a, b;
        cin >> a >> b;
        --a;--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //１個だけの時?
    if(dfs(0,0)){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }
    return 0;
}
