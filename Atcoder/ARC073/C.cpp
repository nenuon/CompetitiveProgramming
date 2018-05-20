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

//方針

int main(){
    ll N, T;
    cin >> N >> T;
    ll t[N];
    FOR(i, 0, N) cin >> t[i];
    ll start = t[0], end = start + T, ans = 0;
    FOR(i, 1, N){
        if(end <= t[i]){
            ans += end - start;
            start = t[i];
            end = start + T;
        }
        //被ってる
        else{
            end = t[i] + T;
        }
    }
    ans += end - start;
    cout << ans << endl;
}
