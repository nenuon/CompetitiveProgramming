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

//問題
//良い集合に対して不必要な数字の数
//方針
//全探索
vector<ll> a(400);
bool used[400];
int N, K;

int dfs(ll sum){
    int ret = 0;
    if(sum >= K) ret++;
    if(sum < K) return ret;
    FOR(i, 0, N){
        if(!used[i]){
            used[i] = true;
            ret += dfs(sum-used[i]);
            used[i] = false;
        }
    }
    return ret;
}

int main(){
    cin>>N>>K;
    ll sum = 0;
    FOR(i, 0, N){
        cin>>a[i];
        sum += a[i];
    }
    if(sum<K){
        cout << N << endl;
        return 0;
    }
    //sort(a.begin(), a.end());
    cout << dfs(sum) << endl;
}
