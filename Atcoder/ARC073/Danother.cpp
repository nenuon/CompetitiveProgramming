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
//dp[i][何個入れたか][重さ-w1]
//dp[N+1][N+1][4*N+1]

int main(){
    int N;
    cin >> N;
    ll W, w[N], v[N];
    cin >> W;
    FOR(i, 0, N) cin >> w[i] >> v[i];
    vector<vector<ll> >
    cout << ans << endl;
}
