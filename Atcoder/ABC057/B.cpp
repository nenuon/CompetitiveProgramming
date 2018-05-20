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

ll llabs(ll x){
    return x>0?x:-x;
}

int main(void){
    int N, M;
    cin >> N >> M;
    ll a[N], b[N], c[M], d[M];
    FOR(i, 0, N) cin>>a[i]>>b[i];
    FOR(i, 0, M) cin>>c[i]>>d[i];
    FOR(i, 0, N){
        ll MIN = 999999999;
        ll p;
        FOR(j, 0, M){
            if(MIN > llabs(a[i]-c[j]) + llabs(b[i]-d[j])){
                MIN = llabs(a[i]-c[j]) + llabs(b[i]-d[j]);
                p = j;
            }
        }
        cout << p+1 << endl;
    }
}
