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

int main(){
    ll H, W;
    cin >> H >> W;
    if(W % 3 == 0 || H % 3 == 0){
        cout << 0 << endl;
        return 0;
    }
    ll a, b, c;
    ll MAX, MIN;
    ll ans = pow(10, 15);
    FOR(h,1,H){
        a = W * h;
        b = (W/2) * (H - h);
        c = ((W+1)/2) * (H - h);
        MAX = max(a, max(b, c));
        MIN = min(a, min(b, c));
        ans = min(ans, MAX - MIN);
        b = (H-h)/2 * W;
        c = (H-h+1)/2 * W;
        MAX = max(a, max(b, c));
        MIN = min(a, min(b, c));
        ans = min(ans, MAX - MIN);
    }

    FOR(w,1,W){
        a = H * w;
        b = (H/2) * (W - w);
        c = ((H+1)/2) * (W - w);
        MAX = max(a, max(b, c));
        MIN = min(a, min(b, c));
        ans = min(ans, MAX - MIN);
        b = (W-w)/2 * H;
        c = (W-w+1)/2 * H;
        MAX = max(a, max(b, c));
        MIN = min(a, min(b, c));
        ans = min(ans, MAX - MIN);
    }
    cout << ans << endl;
}
