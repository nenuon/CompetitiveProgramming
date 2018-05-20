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

ll llabs(ll x){
    return x>=0?x:-x;
}

bool hugou(double x){
    return x >= 0;
}
double A[100000];
int main(){
    int n;
    cin >> n;
    double sum = 0;
    double ans = 0;
    FOR(i, 0, n) cin >> A[i];

    //000000注意
    int j = 0;
    while(A[j]==0 && j<n) j++;
    ans += (j-1) * 2 + 1;
    if(A[j]>0) sum = -1;
    else if(A[j]<0) sum = 1;
    else cout << "err" << endl;

    FOR(i, j, n){
        double a = A[i];
        if(sum+a==0){
            ans++;
            if(sum<0) sum = 1;
            else sum = -1;
        }
        else if(!(hugou(sum)^hugou(sum+a))){
            ans += fabs(sum+a) + 1;
            if(sum<0) sum = 1;
            else sum = -1;
        }
        else if(hugou(sum)^hugou(sum+a)) sum += a;
    }
    printf("%.0lf\n", ans);
}
