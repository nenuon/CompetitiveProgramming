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
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
class DivisorsPower {
    public:
    long long findArgument(long long n) {
        ll ans = 2e18;
        FOR(b,2,70) {
            ll a = pow(1.0*n,1.0/b)+1e-9;
            ll p = 1;
            FOR(i,0,b) p *= a;
            if(p != n) continue; 
            int cnt = 0;
            for(int i = 1; i * i <= a; i++) {
                if(a % i == 0) {
                    cnt += 1 + (a/i!=i);
                }
            }
            if(cnt == b) ans = min(ans, a);
        }
        return ans == 2e18 ? -1 : ans;
    }
};
