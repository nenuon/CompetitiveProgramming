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

int main(){
    string N;
    int K;
    cin>>N>>K;
    int n = N.length();
    bool D[10];
    FOR(i, 0, 10) D[i] = false;
    FOR(i, 0, K){
        int num;
        cin>>num;
        D[num] = true;//trueは嫌い
    }
    int ans = 0;
    FOR(i, 0, n){
        FOR(j, 0, 10){
            if(((N[i]-'0') <= j) && !D[j]){
                ans *= 10;
                ans += j;
                break;
            }
        }
    }
    if(ans<n){
        N = "1";
        FOR(i, 0, n) N.push_back('0');
        FOR(i, 0, n+1){
            FOR(j, 0, 10){
                if(((N[i]-'0') <= j) && !D[j]){
                    ans *= 10;
                    ans += j;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
