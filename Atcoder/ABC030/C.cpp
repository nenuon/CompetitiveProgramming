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
//とりあえず乗った方が良い？
//待つぐらいなら乗った方が良いでしょ

int main(){
    int N, M;
    ll X, Y;
    cin>>N>>M>>X>>Y;
    ll a[N], b[M];
    FOR(i, 0, N) scanf("%lld", a+i);
    FOR(i, 0, M) scanf("%lld", b+i);
    ll ans = 0;
    ll now = 0;
    int next = 1;//1->a, -1->b
    int aid = 0, bid = 0;
    while( !((next==1&&(now>a[N-1])) || (next==-1&&now>b[M-1])) ){
        if(next==1){
            if(a[aid] >= now){
                now = a[aid] + X;
                next *= -1;
            }
            aid++;
        }
        else{
            if(b[bid] >= now){
                now = b[bid] + Y;
                next *= -1;
                ans++;
            }
            bid++;
        }
    }
    cout << ans << endl;
}
