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

//方針
//小さい数字から0, 1, 2, ...としていけば良い
typedef pair<ll, int> P;
bool mysort(P x, P y){
    return x.second < y.second;
}
int main(){
    int N;
    cin>>N;
    vector<ll> in(N);
    vector<P> a;//値、場所
    FOR(i, 0, N){
        cin >> in[i];
        a.push_back(make_pair(in[i], i));
    }
    sort(a.begin(), a.end());
    sort(in.begin(), in.end());
    a[0].first = 0;
    ll j = 0;
    FOR(i, 1, N){
        if(in[i-1]<in[i]) j++;
        a[i].first = j;
    }
    sort(a.begin(), a.end(), mysort);
    FOR(i, 0, N) printf("%lld\n", a[i].first);
}
