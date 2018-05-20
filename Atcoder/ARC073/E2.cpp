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

ll llabs(ll x){
    return x>0?x:-x;
}
ll x[200000], y[200000];
int main(){
    int N;
    cin >> N;

    FOR(i, 0, N) cin >> x[i] >> y[i];
    vector<int> ind(N);
    FOR(i, 0, N) ind[i] = i;

    //xでそーと
    sort(ind.begin(), ind.end(), [](int i, int j){
        return x[i] < x[j];
    });

    ll ans = 9999999999;
    int i = ind[0], j = ind[N-1];
    ans = min(ans, llabs(x[j]-x[i])*llabs(y[j]-y[i]));
    ans = min(ans, llabs(x[j]-y[i])*llabs(y[j]-x[i]));
    ans = min(ans, llabs(y[j]-x[i])*llabs(x[j]-y[i]));
    ans = min(ans, llabs(y[j]-y[i])*llabs(x[j]-x[i]));

    //yでそーと
    sort(ind.begin(), ind.end(), [](int i, int j){
        return y[i] < y[j];
    });

    i = ind[0], j = ind[N-1];
    ans = min(ans, llabs(x[j]-x[i])*llabs(y[j]-y[i]));
    ans = min(ans, llabs(x[j]-y[i])*llabs(y[j]-x[i]));
    ans = min(ans, llabs(y[j]-x[i])*llabs(x[j]-y[i]));
    ans = min(ans, llabs(y[j]-y[i])*llabs(x[j]-x[i]));

    cout << ans << endl;
}
