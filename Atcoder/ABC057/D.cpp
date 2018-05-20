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
int N,A,B;

double factorial(double k){
    double sum = 1;
    for (int i = 1; i <= k; ++i) sum *= i;
    return sum;
}

int main(void){
    cin>>N>>A>>B;
    vector<ll> v(N);
    FOR(i, 0, N) cin>>v[i];
    sort(v.rbegin(), v.rend());
    double ave;//平均値
    double sum = 0;//合計
    double maxAve = -999;//平均値の最大
    double vmin = v[0];//使わなきゃいけない最小値
    int usevmin = 0;//使わなきゃいけない最小値の個数
    int num = 0;
    FOR(i, 0, N){
        sum += v[i];
        ave = sum/(i+1);
        if(i+1>A && v[0]!=v[i]) break;
        if(vmin == v[i]) usevmin++;
        else{
            vmin = v[i];
            usevmin = 1;
        }
        maxAve = ave;
        num = i+1;
    }
    if(usevmin>=A){
        printf("%.06lf\n", maxAve);
        double ans = 0;
        FOR(i, A, B+1){
            if(i>usevmin) break;
            ans += double(factorial(usevmin) / (factorial(usevmin-i) * factorial(i)));
        }
        printf("%.0lf\n", ans);
        return 0;
    }
    double vmin_n = 0;//使われる数の最小値の個数
    FOR(i, 0, N) if(vmin==v[i]) vmin_n++;
    //vim_n C usevmin
    //cout << usevmin << vmin_n << endl;
    printf("%.06lf\n", maxAve);
    printf("%.0lf\n",double(factorial(vmin_n)/(factorial(vmin_n-usevmin)*factorial(usevmin))));
}
