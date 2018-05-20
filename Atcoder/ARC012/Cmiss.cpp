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

vector<string> go;

bool ok(int y, int x){
    return y >= 0 && x >= 0 && y < 19 && x < 19; 
}

int isEnd(int y, int x, string s){
    int ans = 0;
    if(go[y][x]!=s[0]) return 0;
    FOR(vy, -1, 2){
        FOR(vx, -1, 2){
            if(vy==0 && vx==0) continue;
            int ret = 1;
            int nexty = y;
            int nextx = x;
            while(1){
                nexty += vy;
                nextx += vx;
                if(go[nexty][nextx]==s[0]){
                    ret++;
                }
                else break;
            }
            ans = max(ans, ret);
        }
    }
    return ans;
}

//how many go
/*
int dfs(int y, int x, string s){
    if(ok(y, x)) return 0;
    if(go[y][x]!=s[0]) return 0;
    int ans = 0;
    FOR(vy, -1, 2){
        FOR(vx, -1, 2){
            int ret = 1;
            int nexty = y, nextx = x;
            if(vy == 0 && vx == 0) continue;
            while(1){
                nexty += vy;
                nextx += vx;
                if(!ok(nexty, nextx)) break;
                go[y][x] = '.';
                ret += dfs(nexty, nextx, s);
                go[y][x] = s[0];
            }
            ans = max(ans, ret);
        }
    }
    return ans;
}
:*/

int main(){
    int black = 0;
    int white = 0;
    FOR(i, 0, 19){
        string s;
        getline(cin, s);
        go.pb(s);
        FOR(j, 0, 19){
            if(s[j] == 'o') black++;
            else if(s[j] == 'x') white++;
        }
    }
    if(abs(black-white) >= 2 || white > black){
        cout << "NO" << endl;
        return 0;
    }
    FOR(y, 0, 19){
        FOR(x, 0, 19){
            if(go[y][x]=='.') continue;
            if(black==white){
                if(isEnd(y, x, "x")>=5){
                    cout << "NO" << endl;
                    return 0;
                }
            }
            else{
                if(isEnd(y, x, "o")>=5){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
}