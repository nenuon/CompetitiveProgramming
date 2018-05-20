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

#define pb         push_back
#define mp         make_pair
#define ll         long long
#define PI         acos(-1.0)
#define ALL(A)     ((A).begin(), (A).end())
#define vsort(v)   sort(v.begin(),v.end())
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

vector<string> vs;

bool ok(int y, int x){
    return y > 0 && x > 0 && y < 8 & x < 8;
}

//Is Q 8 directions from y,x ??
bool isPuTable(int y, int x){
    FOR(vy, -1, 2){
        FOR(vx, -1, 2){
            if(vy==0 && vx==0) continue;
            int nexty = y;
            int nextx = x;
            while(1){
                nexty += vy;
                nextx += vx;
                if(ok(nexty, nextx)) continue;
                if(vs[nexty][nextx]=='Q') return false;
            }
        }
    }
    return true;
}

bool dfs(int pos, int nokori){
    if(nokori==0) return true;
    if(pos==64) return false;
    int y = pos/8;
    int x = pos%8;

    if(vs[y][x]=='Q'){
        if(isPuTable(y, x)){
            if(dfs(pos+1, nokori-1)) return true;
        }
    }
    else{
        if(isPuTable(y, x)){
            vs[y][x] == 'Q';
            if(dfs(pos+1, nokori-1)) return true;
            vs[y][x] == '.';
        }
        if(dfs(pos+1, nokori)) return true;
    }
    return false;
}

int main(){
    string s;
    FOR(i, 0, 8){
        getline(cin, s);
        vs.pb(s);
    }
    if(dfs(0, 64)){
        FOR(i, 0, 8) cout << v[i] << endl;
    }
    else cout << "No Answer" << endl;
}