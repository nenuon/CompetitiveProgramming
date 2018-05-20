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
//超えるまでたす、あとは微調整でok

ll X;
/*
ll dfs(ll n, ll i){
    if(n==0) return i-1;
    if(n<0) return 999999999;
    if(i>X) return 999999999;
    ll ret = 999999999;
    ret = min(ret, min(dfs(n-i, i+1), dfs(n, i+1)));
    return ret;
}
*/
ll llabs(ll a){
    return (a>0 ? a:-1*a);
}

int main(){
    cin>>X;
    X=llabs(X);
    ll i = 0;
    ll sum = 0;
    while(sum<X){
        i++;
        sum+=i;
    }
    sum-=i;
    i--;
    ll ans = 0;
    if(sum==X) ans = i;
    else if(i==X) ans = i;
    else ans = i+1;
    cout << ans << endl;
}
