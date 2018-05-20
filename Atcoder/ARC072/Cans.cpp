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
    return x>=0?x:-x;
}

ll A[100000];
int main(){
    int n;
    cin >> n;
    ll sum = 0;
    ll ans1 = 0, ans2 = 0;
    FOR(i, 0, n) cin >> A[i];
    //+-+-...
    int f = 1;//1=+
    FOR(i, 0, n){
        ll a = A[i];
        if(f*(sum+a)<=0){
            ans1 += llabs(sum+a) + 1;
            sum = f;
        }
        else sum += a;
        f *= -1;
    }
    //-+-+...
    f = -1;
    sum = 0;
    FOR(i, 0, n){
        ll a = A[i];
        if(f*(sum+a)<=0){
            ans2 += llabs(sum+a) + 1;
            sum = f;
        }
        else sum += a;
        f *= -1;
    }
    cout << min(ans1, ans2) << endl;
}
