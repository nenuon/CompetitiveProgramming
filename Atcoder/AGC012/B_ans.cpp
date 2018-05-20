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

int N,M,Q;
vector<vector<int> > G(N);
vector<vector<int> > dp(N, vector<int>(11, 0));

void solve(int v, int d, int c){
    if(dp[v][d]!=0) return;
    for(int i = d; i>=0 && dp[v][i] == 0; --i) dp[v][i] = c;
    if(d == 0) return;
    for(int x : G[v]) solve(x, d-1, c);
}

int main(){
    cin>>N>>M;
    FOR(i, 0, M){
        int a, b;
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cin>>Q;
    vector<vector<int> > query(Q, vector<int>(3, 0));
    FOR(i, 0, Q){
        cin>>query[i][0]>>query[i][1]>>query[i][2];
        query[i][0]--;
    }
    //処理
    for(int q = Q - 1; q >= 0; --q) solve(query[q][0], query[q][1], query[q][2]);
    FOR(i, 0, N) cout << dp[i][0] << endl;
}
