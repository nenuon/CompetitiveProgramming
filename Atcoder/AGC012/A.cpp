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

int main(){
    int N;
    cin>>N;
    vector<ll> a;
    FOR(i, 0, 3*N){
        ll in;
        cin >> in;
        a.push_back(in);
    }
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    FOR(i, 0, 2*N){
        if(i%2==1) ans+=a[i];
    }
    cout << ans << endl;
}
