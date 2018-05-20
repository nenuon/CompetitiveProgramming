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

int main(void){
    int K, S;
    cin>>K>>S;
    int ans = 0;
    FOR(X, 0, K+1){
        FOR(Y, 0, K+1){
            if(S-X-Y>=0 && S-X-Y<=K) ans++;
        }
    }
    cout << ans << endl;
}
