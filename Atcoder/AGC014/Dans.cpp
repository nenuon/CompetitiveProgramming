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
typedef vector<int> vi;

int main(){
    int N;
    cin >> N;
    vector<vi> ed(N);
    vi deg(N);
    FOR(i,0,N-1){
        int a, b;
        cin >> a >> b;
        --a;--b;
        ed[a].push_back(b);
        ed[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    vi deg1, deg0;
    FOR(y,0,N){
        if(deg[y] == 1) deg1.push_back(y);
        if(deg[y] == 0) deg0.push_back(y);
    }

    vi dead(N);
    auto kill = [&](int found){
        dead[found] = 1;
        for(auto& y : ed[found]){
            --deg[y];
            if(deg[y] == 1) deg1.push_back(y);
            if(deg[y] == 0) deg0.push_back(y);
        }
    };

    for(;;){
        while(!deg0.empty() && dead[deg0.back()]) deg0.pop_back();
        if(!deg0.empty()){
            cout << "First" << endl;
            return 0;
        }

        while(!deg1.empty() && (dead[deg1.back()] || deg[deg1.back()] != 1)) deg1.pop_back();
        if(deg1.empty()) break;
        int x = deg1.back();
        assert(deg[x] == 1);
        int found = -2;
        for(auto& y, ed[x]){
            if(!dead[y]) found = y;
        }

        assert(found!=-2);
        kill(found);

        while (!deg0.empty() && dead[deg0.back()]) deg0.pop_back();
        assert(!deg0.empty());
        int f = deg0.back();
        deg0.pop_back();
        kill(f);
    }

    cout << "Second" << endl;
    exit(0);
}
