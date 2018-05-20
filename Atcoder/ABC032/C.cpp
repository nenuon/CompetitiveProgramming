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
ll times[100010];
int main(){
    ll N, K;
    cin >> N >> K;
    times[0] = 1;
    bool fin = false;
    FOR(i, 1, N+1){
        ll in;
        cin >> in;
        if(in==0) fin = true;
        //times[i] = times[i-1] * in;
        times[i] = in;
    }
    if(fin){
        cout << N << endl;
        return 0;
    }
    ll l = 0, r = 1, len = 0;
    //しゃくとり法
    ll x = times[r];
    while(r <= N){
        //while((times[r]/times[l]) <= K && r <= N){
        while(x <= K && r <= N){
            len = max(len, r - l);
            r++;x*=times[r];
        }
        l++;x/=times[l];
        if(l==r) r++;x*=times[r];
    }
    cout << len << endl;
}
