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
    int N;
    double C, K;
    cin >> N >> C >> K;
    vector<double> T(N, 0);
    FOR(i, 0, N) cin >> T[i];

    sort(T.begin(), T.end());
    int ans = 0;
    //先頭の人
    double t = T[0];
    int people = 0;
    bool last = false;
    FOR(i, 0, N){
        //バス出発
        if(t + K < T[i]){
            ans++;
            people = 1;
            t = T[i];
        }
        //乗れた
        else{
            people++;
            //あるバスで最後の乗客だった場合
            if(people==C){
                ans++;
                people = 0;
                if(i+1==N) last = true;
                //次の先頭の人
                t = T[i+1];
            }
        }
    }
    if(!last) ans++;
    cout << ans << endl;
}
