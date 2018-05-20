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

int isis[8];
int pas[8][8];
int N;

int dfs(int next, int nokori){
    if(nokori==0) return 1;
    isis[next] = 1;
    int res = 0;
    FOR(i, 1, N){
        if(pas[next][i]==1 && isis[i]==0) res += dfs(i, nokori-1);
    }
    isis[next] = 0;
    return res;
}

int main(){
    int M;
    cin >> N >> M;
    //int pas[N][N];
    FOR(i, 0, M){
        int a, b;
        cin >> a >> b;
        pas[a-1][b-1] = pas[b-1][a-1] = 1;
    }

    int ans = 0;
    cout <<  dfs(0, N-1) << endl; 
}