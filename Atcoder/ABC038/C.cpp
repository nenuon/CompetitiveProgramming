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

//答え見た

int main(){
    int N;
    cin >> N;
    int a[N+1];
    FOR(i, 0, N) cin>>a[i];
    a[N] = 0;
    int l = 0, r = 0;
    ll ans = 0;
    while(l < N){
        while(a[r+1] > a[r]) r++;
        ans += r - l + 1;
        l++;
        if(l==r+1) r++;
    }
    cout << ans << endl;
}
