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

int N;
ll A, B;
ll h[100000];
bool C(ll x){
    ll cnt = 0;
    FOR(i,0,N){
        ll now = h[i] - B * x;
        if(now <= 0) continue;
        cnt += (now + A - B - 1)/(A - B);
    }
    return cnt <= x;
}
int main(){
    cin >> N >> A >> B;
    FOR(i,0,N) cin >> h[i];
    ll l = -1, r = 1000000005;
    while(r-l>1){
        ll cen = (r + l) / 2;
        if(C(cen)) r = cen;
        else l = cen;
    }
    cout << r << endl;
    return 0;
}
