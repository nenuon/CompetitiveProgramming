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

bool isEnd(){
    FOR(y, 0, 19){
        FOR(x, 0, 19){
            if(go[y][x]!='.'){
                string s = "aaa";
                s[0] = go[y][x];
                //move
                FOR(vy, -1, 2){
                    FOR(vx, -1, 2){
                        if(vy==0 && vx==0) continue;
                        int ret = 1;
                        int nexty = y;
                        int nextx = x;
                        while(1){
                            nexty += vy;
                            nextx += vx;
                            if(!ok(nexty, nextx)) break;
                            if(go[nexty][nextx]==s[0]){
                                ret++;
                            }
                            else break;
                        }
                        if(ret >= 5) return true;
                    }
                }
            }
        }
    }
    return false;
}

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
    if(black-white >= 2 || white > black){
        cout << "NO" << endl;
        return 0;
    }

    if(black==0){
        cout << "YES" << endl;
        return 0;
    }

    FOR(y, 0, 19){
        FOR(x, 0, 19){
            if(go[y][x]!='.'){
                string s = "aaa";
                s[0] = go[y][x];
                go[y][x] = '.';
                if(isEnd()){
                    cout << "NO" << endl;
                    return 0;
                }
                go[y][x] = s[0];
            }
        }
    }
    cout << "YES" << endl;
}