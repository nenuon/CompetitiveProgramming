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

//差の絶対値が同じ人は二人(0を除く)
//Nが奇数の時:差は0~N-1,0の人は真ん中のみ
//Nが偶数の時:差は1~N-1
//iさんは2通り

ll MOD = pow(10, 9) + 1;

int main(void){
    int N;
    cin >> N;
    int d[N];
    ll ans = 1;
    FOR(i, 0, N) d[i] = 0;
    FOR(i, 0, N){
        int n;cin>>n;
        d[n]++;
        if(n!=0 && d[n]==3){
            cout << 0 << endl;
            return 0;
        }
        else if(n==0 && d[n]==2){
            cout << 0 << endl;
            return 0;
        }
        else if(d[n]==2){
            ans *= 2;
            ans %= MOD;
        }
        else if(N%2==0 && n==0){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
