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
    int num[5];
    FOR(i, 0, 5) cin>>num[i];
    map<int, int> sum;
    FOR(i, 0, 3){
        FOR(j, i+1, 4){
            FOR(k, j+1, 5){
                int n = num[i]+num[j]+num[k];
                n = -n;
                sum[n] = 1;
            }
        }
    }
    auto itr = sum.begin();
    itr++;itr++;
    int ans = itr->first;
    ans = -ans;
    cout << ans << endl;
}
