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

int a[100000];
int N;
ll INF = -1;
//再帰関数+メモ化
//位置は0~N-1
ll dp[100000][2];
ll dfs(int n, int bef){
    //N本目についたらおしまい
    if(n == N-1) return abs(a[N-1] - a[n-bef]);
    //N本目を超えてしまう場合注意
    if(n == N) return abs(a[N-1] - a[N-2]);
    //すでに計算済みならそれを返す
    if(dp[n][bef-1]!=INF) return dp[n][bef-1];

    ll ret = abs(a[n] - a[n-bef]);
    ret += min(dfs(n+1, 1), dfs(n+2, 2));
    return dp[n][bef-1] = ret;
}

int main(){
    cin>>N;
    FOR(i, 0, 100000) a[i] = 0;
    FOR(i, 0, N) cin>>a[i];
    FOR(i, 0, 100000) FOR(j, 0, 2) dp[i][j] = INF;
    cout << min(dfs(1, 1), dfs(2, 2)) << endl;
}
