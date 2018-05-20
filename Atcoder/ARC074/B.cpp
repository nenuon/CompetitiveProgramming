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
#include <bitset>
using namespace std;

#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

typedef long long ll;

ll a[300010];
priority_queue<ll> bque;
priority_queue<ll, vector<ll>, greater<ll> > aque;
int main(){
    int N;
    cin >> N;
    FOR(i,0,3*N) cin >> a[i];
    ll asum[N+1];
    ll bsum[N+1];
    asum[0] = 0;
    bsum[0] = 0;
    FOR(i,0,N){
        aque.push(a[i]);
        bque.push(a[3*N-1-i]);
        asum[0] += a[i];
        bsum[0] += a[3*N-1-i];
    }
    FOR(i,0,N){
        // 左側について
        aque.push(a[N+i]);
        asum[i+1] = asum[i] + a[N+i];
        asum[i+1] -= aque.top();
        aque.pop();

        //右側について
        bque.push(a[2*N-1-i]);
        bsum[i+1] = bsum[i] + a[2*N-1-i];
        bsum[i+1] -= bque.top();
        bque.pop();
    }
    ll ans = -1e14;
    FOR(i,0,N+1){
        ans = max(ans, asum[i] - bsum[N-i]);
    }
    cout << ans << endl;
    return 0;
}
