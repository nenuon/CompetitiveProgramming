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

const ll INF = 1e18;

int main(){
    int N, M;
    cin >> N >> M;

    const int NMAX = 1000;
    const int MMAX = 2000;
    int a[MMAX], b[MMAX];
    ll c[MMAX];

    FOR(i,0,M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;b[i]--;
        //c[i] = -c[i];
    }

    ll dist[NMAX];
    FOR(i,0,N) dist[i] = -INF;

    dist[0] = 0;

    FOR(i,0,N-1){
        FOR(j,0,M){
            dist[b[j]] = max(dist[b[j]], dist[a[j]] + c[j]);
        }
    }
    ll ans1 = dist[N-1];

    FOR(i,0,N-1){
        FOR(j,0,M){
            dist[b[j]] = max(dist[b[j]], dist[a[j]] + c[j]);
        }
    }
    ll ans2 = dist[N-1];
    if(ans1!=ans2) cout << "inf" << endl;
    else cout << ans1 << endl;
}
