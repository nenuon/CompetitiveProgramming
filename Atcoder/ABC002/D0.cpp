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

int N, M;
bool friends[12][12];
bool used[12];


int main(){
    cin >> N >> M;
    FOR(i,0,N) FOR(j,0,N) friends[i][j] = false;
    FOR(i,0,M){
        int x, y;
        cin >> x >> y;
        x--;y--;
        friends[x][y] = true;
        friends[y][x] = true;
    }
    int ans = 0;
    //N個をどう選ぶか
    FOR(i, 0, 1<<N){
        int cnt = 0;
        FOR(j, 0, N){
            if((i>>j)%2==0) continue;
            cnt++;
        }
        bool ok = true;
        FOR(k,0,N){
            FOR(l,0,N){
                if(k==l) continue;
                if(i>>k & i>>l & 1 && !friends[k][l]){
                    ok = false;
                    break;
                }
            }
        }
        if(ok) ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
