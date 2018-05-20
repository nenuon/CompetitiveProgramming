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
int N,A,B;
vector<ll> v(N);
int main(void){
    cin>>N>>A>>B;

    FOR(i, 0, N) cin>>v[i];
    sort(v.rbegin(), v.rend());
}
