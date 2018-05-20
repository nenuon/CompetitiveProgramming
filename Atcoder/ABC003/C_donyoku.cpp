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

#define pb         push_back
#define mp         make_pair
#define ll         long long
#define PI         acos(-1.0)
#define ALL(A)     ((A).begin(), (A).end())
#define vsort(v)   sort(v.begin(),v.end())
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    int N, K;
    cin >> N >> K;
    vector<double> R;
    FOR(i, 0, N){
        int r;
        cin >> r;
        R.pb(r);
    }
    vsort(R);
    double ans = 0;
    FOR(i, N-K, N){
        ans = (ans+R[i])/2;
    }
    printf("%.09lf\n" ,ans);
}