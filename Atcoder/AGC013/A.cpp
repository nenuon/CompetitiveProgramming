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

//最初から見ていくO(n)

int main(){
    int N;
    cin >> N;
    if(N==1){
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    bool up = false;
    bool down = false;
    //bool con = true;
    ll now, bef;
    FOR(i, 0, N){
        cin>>now;
        if(i==0){
            bef = now;
            continue;
        }
        else if(now>bef){
            if(down){
                ans++;
                up = false;
                down = false;
                bef = now;
                continue;
            }
            up = true;
            down = false;
        }
        else if(now<bef){
            if(up){
                ans++;
                up = false;
                down = false;
                bef = now;
                continue;
            }
            up = false;
            down = true;
        }
        bef = now;
    }
    cout << ans+1 << endl;
}
