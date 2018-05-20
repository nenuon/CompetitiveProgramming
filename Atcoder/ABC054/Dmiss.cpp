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
    int N;
    double Ma, Mb;
    cin >> N >> Ma >> Mb;
    int ABC[N][3];
    FOR(i, 0, N){
        cin >> ABC[i][0] >> ABC[i][1] >> ABC[i][2];
    }
    int MIN = 1000000;
    FOR(i, 0, 1<<N){
        double a = 0;
        double b = 0;
        int c = 0;
        FOR(j, 1, N){
            if((i>>j)%2==0) continue;
            a += ABC[j][0];
            b += ABC[j][1];
            c += ABC[j][2];
        }
        if(Ma/Mb == a/b) MIN = min(c, MIN);
    }
    if(MIN!=1000000){
        cout << MIN << endl;
        return 0;
    }
    else cout << "-1" << endl;
}