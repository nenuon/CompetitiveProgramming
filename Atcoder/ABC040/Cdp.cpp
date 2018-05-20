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

//動的計画法
//dp[i]:=i番目の柱に行く最小値

int a[100000];
int N;
ll dp[100001];
int main(){
    cin>>N;
    FOR(i, 0, 100000) a[i] = 0;
    FOR(i, 0, N) cin>>a[i];
    FOR(i, 0, 100001) dp[i] = 999999999999;
    dp[0] = 0;
    dp[1] = 0;//1番目の柱に行く最小値はもちろん0
    dp[2] = abs(a[1] - a[0]);//2番目の柱には1番目からくるしかない
    FOR(i, 3, N+1){
        //1個前と2個前どっちからきた方がi番目は最小値になるか
        dp[i] = min(dp[i-2]+abs(a[i-1]-a[i-3]), dp[i-1]+abs(a[i-1]-a[i-2]));
    }
    cout << dp[N] << endl;
}
