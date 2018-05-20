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

//素数で割っていく
ll MOD = pow(10,9) + 7;
bool isPrime[1001];

void prime(){
    FOR(i, 0, 1001) isPrime[i] = true;
    FOR(x, 2, 1001){
        if(!isPrime[x]) continue;
        for(int i=x*2; i<1001; i+=x){
            isPrime[i] = false;
        }
    }
}

ll llpow(int x, int y){
    int n = y;
    int ret = 0;
    //単純に割っていけばよかった,少しめんどくしちゃってる
    while(x>=n && x%n==0){
        n *= y;
        ret++;
    }
    return ret;
}

int main(void){
    prime();
    int N;
    cin>>N;
    ll num[N+1];
    FOR(i, 0, N+1) num[i] = i;
    ll ans = 1;
    FOR(i, 2, N+1){
        if(!isPrime[i]) continue;
        ll ruijo = 0;
        FOR(j, 2, N+1){
            if(num[j]%i==0){
                //何乗か
                ll rui = llpow(num[j], i);
                ruijo += rui;
                num[j] /= pow(i, rui);
            }
        }
        ans *= (ruijo+1) % MOD;
        ans = ans % MOD;
    }

    cout << ans << endl;
}
