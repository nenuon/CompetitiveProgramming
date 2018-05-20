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

int pos(int y, int x){
    return 1000 * y + x;
}

bool visited[1000000];

int main(){
    FOR(i,0,1000000) visited[i] = false;
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> vs;
    int S;
    FOR(i,0,H){
        string in;
        cin >> in;
        vs.push_back(in);
        FOR(j,0,in.length()){
            if(in[j]=='S'){
                S = pos(i, j);
            }
        }
    }
    int vx[4] = {0,1,0,-1};
    int vy[4] = {-1,0,1,0};
    queue<int> que;
    que.push(S);
    visited[S] = true;
    int MIN = min(min(S/1000, abs(H-1-S/1000)), min(S%1000, abs(W-1-S%1000)));
    queue<int> quek;
    quek.push(1);
    while(!que.empty()){
        int q = que.front();que.pop();
        int nowy = q / 1000;
        int nowx = q % 1000;
        int k = quek.front();quek.pop();
        if(k>K) continue;
        FOR(i,0,4){
            int nexty = nowy + vy[i];
            int nextx = nowx + vx[i];
            if(nexty >= H || nexty < 0 || nextx >= W || nextx < 0) continue;
            if(vs[nexty][nextx]=='#' || visited[pos(nexty, nextx)]) continue;
            que.push(pos(nexty, nextx));
            k++;
            quek.push(k);
            visited[pos(nexty, nextx)] = true;
            MIN = min(MIN, min(min(nexty, abs(H-1-nexty)),min(nextx, abs(W-1-nextx))));
        }
    }
    if(MIN==0) cout << 1 << endl;
    else cout << (MIN+K-1)/K + 1 << endl;
}
