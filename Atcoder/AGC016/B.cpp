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

#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int  a[n];
    FOR(i,0,n) scanf("%d", a + i);
    int mx = 0;
    FOR(i,0,n) mx = max(mx, a[i]);
    int cnt = 0; // 大きい方
    FOR(i,0,n){
        if(a[i] < mx - 1){
            puts("No");
            return 0;
        }
        if(a[i] == mx){
            cnt++;
        }
    }
    if(mx == n - 1 && cnt == n){
        puts("Yes");
        return 0;
    }
    // a[i] == mx -> c[i] is not unique
    // a[i] == mx - 1 - > c[i] is unique
    if(cnt == 1){
        puts("No");
        return 0;
    }
    int p = n - cnt;
    int q = cnt;
    if(p <= mx - 1 && mx <= p + q / 2){
        puts("Yes");
    }
    else{
        puts("No");
    }
    return 0;
}
