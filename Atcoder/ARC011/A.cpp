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
    int n,m,N,ans=0,sairi=1000;
    cin >> m >> n >> N;
    ans=N;
    sairi=N;
    while(sairi>=m){
        ans+=sairi/m*n;
        sairi=sairi/m*n+sairi%m;
    }
    cout << ans << endl;
}