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
using namespace std;

#define pb         push_back
#define mp         make_pair
#define ll         long long
#define PI         acos(-1.0)
#define ALL(A)     ((A).begin(), (A).end())
#define vsort(v)   sort(v.begin(),v.end())
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    int n, c;
    cin >> n >> c;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    int ans = 1000 * 100;
    FOR(sima1, 1, 11){
        FOR(sima2, 1, 11){
            int ret = 0;
            if(sima1 == sima2) continue;
            FOR(i, 0, n){
                if(i%2==0){
                    if(sima1!=a[i]) ret++;
                }
                else{
                    if(sima2!=a[i]) ret++;
                }
            }
            ret *= c;
            ans = min(ans, ret);
        }
    }
    cout << ans << endl;
}
