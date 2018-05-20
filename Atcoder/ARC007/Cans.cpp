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

#define pb         push_back
#define mp         make_pair
#define ll         long long
#define PI         acos(-1.0)
#define ALL(A)     ((A).begin(), (A).end())
#define vsort(v)   sort(v.begin(),v.end())
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    string tv;
    getline(cin, tv);
    int N = tv.length();

    bool b[N];
    FOR(i, 0, N){
        if(tv[i]=='o') b[i] = true;
    }
    int ret = 999;
    FOR(i, 0, 1<<N){
        int cnt = 0;
        bool now[N];

        FOR(j, 0, N){
            if((i>>j)%2==0) continue;
            cnt++;

            FOR(k, 0, N){
                if(!b[k]) continue;
                now[(j+k)%N] = true;
            }
        }
        bool flag = true;
        FOR(j, 0, N) if(!now[j]) flag = false;
        if(flag) ret = min(ret, cnt);
    }
    cout << ret << endl;
}