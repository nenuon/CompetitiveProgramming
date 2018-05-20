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
//K通り->(K-1)通り->(K-1)通り->...N回かける
int main(){
    int N,K;
    ll ans;
    cin>>N>>K;
    ans = K;
    FOR(i, 0, N-1) ans *= (K-1);
    cout << ans << endl;
}
