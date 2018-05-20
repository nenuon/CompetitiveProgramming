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


//左端から+1
//右端から-1
//いもす法と言うらしい
map<int, int> ml;
map<int, int> mr;
int main(){
    int N, Q;
    cin>>N>>Q;
    FOR(i, 0, Q){
        int l, r;
        cin>>l>>r;
        r++;
        if(ml.count(l)==0) ml[l] = 0;
        if(mr.count(r)==0) mr[r] = 0;
        ml[l]++;
        mr[r]++;
    }
    int plus = 0, minus = 0;
    FOR(i, 0, N){
        if(ml.count(i+1)) plus += ml[i+1];
        if(mr.count(i+1)) minus += mr[i+1];
        int sum = plus - minus;
        if(sum%2==0) cout<<0;
        else cout<<1;
    }
    cout << endl;
}
