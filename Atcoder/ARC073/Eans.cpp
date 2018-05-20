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
    return x>0?x:-x;
}

ll x[200000], y[200000];

int main(){
    int N;cin >> N;
    FOR(i, 0, N) cin >> x[i] >> y[i];
    vector<int> ind(N);
    FOR(i, 0, N) ind[i] = i;


}
