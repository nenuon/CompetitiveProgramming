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

//次の比率を超えるまで

int main(void){
    int N;
    cin >> N;
    ll t, a, sumt = 1, suma = 1;
    FOR(i, 0, N){
        cin>>t>>a;
        ll bai = max((sumt+t-1)/t, (suma+a-1)/a);
        if(bai<=1){
            sumt = t;
            suma = a;
        }
        else{
            sumt = t * bai;
            suma = a * bai;
        }
    }
    cout << sumt + suma << endl;
}
