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
//
int main(){
    int W,H,N;
    cin>>W>>H>>N;
    int x, y, a;
    int yu=H, yd=0, xr=W, xl=0;
    FOR(i, 0, N){
        cin>>x>>y>>a;
        if(a==1) xl = max(x, xl);
        if(a==2) xr = min(x, xr);
        if(a==3) yd = max(y, yd);
        if(a==4) yu = min(y, yu);
    }
    cout << (xr-xl>0?xr-xl:0) * (yu-yd>0?yu-yd:0) << endl;
}
