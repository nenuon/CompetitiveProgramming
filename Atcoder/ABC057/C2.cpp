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

int keta(ll x){
    int ret = 0;
    while(x>0){
        x /= 10;
        ret++;
    }
    return ret;
}

int main(){
    ll N, ans = 1;
    cin>>N;
    for(int i=1; i<=sqrt(N); ++i) if(N%i==0) ans = N/i;
    if(ans==1) cout << keta(N) << endl;
    else cout << keta(ans) << endl;
}
