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

ll x[200000], y[200000];

int main(){
    int N;
    cin >> N;
    FOR(i, 0, N) cin >> x[i] >> y[i];
    vector<int> ind(N);
    FOR(i, 0, N) ind[i] = i;
    sort(ind.begin(), ind.end(), [](int i, int j){
        return x[i] < x[j];
    });
    ll Rmax, Rmin, Bmax, Bmin;
    Rmax = Rmin = x[ind[0]];
    Bmax = Bmin = y[ind[0]];
    FOR(k, 1, N){
        int i = ind[k];
        ll comp1 = 0, comp2 = 0;
        //xがRの時
        if(x[i] > Rmax) comp1 = x[i] - Rmin;
        else if(x[i] < Rmin) comp1 = Rmax - x[i];
        else comp1 = Rmax - Rmin;
        if(y[i] > Bmax) comp1 *= y[i] - Bmin;
        else if(y[i] < Bmin) comp1 *= Bmax - y[i];
        else comp1 *= Bmax - Bmin;

        if(y[i] > Rmax) comp2 = y[i] - Rmin;
        else if(y[i] < Rmin) comp2 = Rmax - y[i];
        else comp2 = Rmax - Rmin;
        if(x[i] > Bmax) comp2 *= x[i] - Bmin;
        else if(x[i] < Bmin) comp2 *= Bmax - x[i];
        else comp2 *= Bmax - Bmin;

        if(comp1<=comp2){
            Rmax = max(Rmax, x[i]);
            Rmin = min(Rmin, x[i]);
            Bmax = max(Bmax, y[i]);
            Bmin = min(Bmin, y[i]);
        }
        else{
            Rmax = max(Rmax, y[i]);
            Rmin = min(Rmin, y[i]);
            Bmax = max(Bmax, x[i]);
            Bmin = min(Bmin, x[i]);
        }
    }
    ll ans = (Rmax-Rmin) * (Bmax-Bmin);
    int i = ind[0], j = ind[N-1];
    ans = min(ans, llabs(x[j]-x[i])*llabs(y[j]-y[i]));
    ans = min(ans, llabs(x[j]-y[i])*llabs(y[j]-x[i]));
    ans = min(ans, llabs(y[j]-x[i])*llabs(x[j]-y[i]));
    ans = min(ans, llabs(y[j]-y[i])*llabs(x[j]-x[i]));

    sort(ind.begin(), ind.end(), [](int i, int j){
        return y[i] < y[j];
    });
    Rmax = Rmin = x[ind[0]];
    Bmax = Bmin = y[ind[0]];
    FOR(k, 1, N){
        int i = ind[k];
        ll comp1 = 0, comp2 = 0;
        //xがRの時
        if(x[i] > Rmax) comp1 = x[i] - Rmin;
        else if(x[i] < Rmin) comp1 = Rmax - x[i];
        else comp1 = Rmax - Rmin;
        if(y[i] > Bmax) comp1 *= y[i] - Bmin;
        else if(y[i] < Bmin) comp1 *= Bmax - y[i];
        else comp1 *= Bmax - Bmin;

        if(y[i] > Rmax) comp2 = y[i] - Rmin;
        else if(y[i] < Rmin) comp2 = Rmax - y[i];
        else comp2 = Rmax - Rmin;
        if(x[i] > Bmax) comp2 *= x[i] - Bmin;
        else if(x[i] < Bmin) comp2 *= Bmax - x[i];
        else comp2 *= Bmax - Bmin;

        if(comp1<=comp2){
            Rmax = max(Rmax, x[i]);
            Rmin = min(Rmin, x[i]);
            Bmax = max(Bmax, y[i]);
            Bmin = min(Bmin, y[i]);
        }
        else{
            Rmax = max(Rmax, y[i]);
            Rmin = min(Rmin, y[i]);
            Bmax = max(Bmax, x[i]);
            Bmin = min(Bmin, x[i]);
        }
    }
    i = ind[0], j = ind[N-1];
    ans = min(ans, llabs(x[j]-x[i])*llabs(y[j]-y[i]));
    ans = min(ans, llabs(x[j]-y[i])*llabs(y[j]-x[i]));
    ans = min(ans, llabs(y[j]-x[i])*llabs(x[j]-y[i]));
    ans = min(ans, llabs(y[j]-y[i])*llabs(x[j]-x[i]));
    ans = min(ans, (Rmax-Rmin) * (Bmax-Bmin));
    cout << ans << endl;
}
