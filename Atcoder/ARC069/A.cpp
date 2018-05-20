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

 
#define ll long long
#define MP make_pair

int main(void){
    ll int N, M;
    cin >> N >> M;
    ll int ans = 0;
    if(N*2<=M){
        ans = N;
        M -= ans*2;
        ans += M/4;
    }
    else{
        ans = M/2;
    }
    cout << ans << endl;
}