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

ll calKeta(ll n){
    int keta = 0;
    while(n>0){
        n /= 10;
        keta++;
    }
    return keta;
}


int main(void){
    ll N;
    cin >> N;
    ll ans = 0;
    for(int i = 1; i<=sqrt(N); ++i){
        if(N%i==0) ans = N / i;
    }
    cout << min(calKeta(N), calKeta(ans)) << endl;
}
