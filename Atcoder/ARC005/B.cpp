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

int H, W;

int encode(int y, int x){
    return y * 1000 + x;
}

bool ok(int y, int x){
    return y >= 0 && x >= 0 && y < H && x < x;
}

int main(){
    cin >> H >> W;
    vector<string> board;
    FOR(i,0,H){
        cin >> board[i]
    }

    int fx = -1;
    int fy = -1;
    FOR(i,0,H){
        FOR(j,0,W){
            if((board[i])[j]=='s'){
                fy = i;
                yx = j;
            }
        }
    }

    queue<int> nowq;
    nowq.push(encode(fy, fx));

    int vy[4] = {1, 0, -1, 0};
    int vx[4] = {0, 1, 0, -1};

    bool check[H][W];
    check[fy][fx]=true;

    FOR(i, 0, 3){
        queue<int> nextq;
        while(!nowq.isEmpty()){
            int now = nowq.top();nowq.pop();
            int y = now / 1000;
            int x = now % 1000;

            FOR(j, 0, 4){
                int ny = y + vy[j];
                int nx = x + vx[j];

                if(!ok(ny, nx)) continue;
                if(check[ny][nx]) continue;

                check[ny][nx] = true;

                if(board[ny][nx]=='g'){
                    cout << "YES" << endl;
                    return 0;
                }
                else if(board[ny][nx]=='#'){
                    nextq.push(encode(ny,nx));
                }
                else{
                    nowq.push(encode(ny,nx));
                }
            }
        }
        nowq = nextq;
    }
    cout << "NO" << endl;
    return 0;
}