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

//平均値に書き換える！

 int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    double ave = 0;
    FOR(i, 0, N){
        cin >> A[i];
        ave += A[i];
    }
    ave /= N;
    ll cost = 0;
    FOR(i, 0, N){
        cost += pow(abs(int(round(ave))-A[i]),2);
    }
    cout << cost << endl;
 }
