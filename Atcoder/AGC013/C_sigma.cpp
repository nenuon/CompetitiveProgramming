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

#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

typedef long long ll;
//my方針
//ぶつカルごとに入れ替わってるー！？！？
//時計回りの蟻について考えれば反時計回りのやつは計算しなくて良い？
//map<自分、入れ替わり>
//2周目は？

//sigmaさん解答

int N,
const int MN = 100010;
ll L, T;
ll X[MN];
int W[MN];
vector<ll> xs[2];

int main(){
    cin>>N>>L>>T;
    FOR(i, 0, N){
        cin>>X[i]>>W[i];
        W[i]--;
    }
    vector<ll> ans;
    ll dif = 0;
    FOR(i, 0, N){
        ll v;
        if(W[i]==0){
            //最終的に何かしらの蟻がいる位置
            v = (X[i]+T)%L;
            //何周してるか？
            dif += (X[i]+T)/L;
        }
        else{
            v = ((X[i]-T)%L+L)%L;
            dif -= (T-X[i]+L-1)/L;
        }
        ans.push_back(v);
    }
    sort(ans.begin(), ans.end());
    dif %= N;
}
