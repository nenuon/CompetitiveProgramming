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
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
// 真ん中の3つをHかWか変えないか全探索
class TaroJiroGrid {
    public:
    int getNumber(vector<string> grid) {
        int N = grid.size();
        // 0行変更
        // 判定
        bool ok = true;
        FOR(x,0,N) {
            int cnt = 1;
            FOR(y,1,N) {
                if(grid[y][x] == grid[y-1][x]) cnt++;
                else cnt = 1;
                if(cnt > N / 2) {
                    ok = false;
                }
            }
        }
        if(ok) return 0;
        if(N >= 1) {
            FOR(y,0,N) {
                vector<string> vs = grid;
                FOR(x,0,N) vs[y][x] = 'W';
                // 判定
                bool ok = true;
                FOR(x,0,N) {
                    int cnt = 1;
                    FOR(y,1,N) {
                        if(vs[y][x] == vs[y-1][x]) cnt++;
                        else cnt = 1;
                        if(cnt > N / 2) {
                            ok = false;
                        }
                    }
                }
                if(ok) return 1;
            }
            FOR(y,0,N) {
                vector<string> vs = grid;
                FOR(x,0,N) vs[y][x] = 'B';
                // 判定
                bool ok = true;
                FOR(x,0,N) {
                    int cnt = 1;
                    FOR(y,1,N) {
                        if(vs[y][x] == vs[y-1][x]) cnt++;
                        else cnt = 1;
                        if(cnt > N / 2) {
                            ok = false;
                        }
                    }
                }
                if(ok) return 1;
            }
        }
        return 2;
    }
};
