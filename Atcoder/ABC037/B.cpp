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
//全探索
int main(){
    int N, Q;
    cin>>N>>Q;
    ll A[N];
    FOR(i, 0, N) A[i] = 0;
    FOR(i, 0, Q){
        int L,R,T;
        cin>>L>>R>>T;
        L--;R--;
        FOR(j, L, R+1) A[j] = T;
    }
    FOR(i, 0, N) cout << A[i] << endl;

}
