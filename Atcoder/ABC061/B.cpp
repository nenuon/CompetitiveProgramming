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

int main(void){
    int N, M;
    cin >> N >> M;
    int r[N];
    FOR(i,0,N) r[i] = 0;
    FOR(i,0,M){
        int a, b;
        cin >> a >> b;
        a--;b--;
        r[a]++;
        r[b]++;
    }
    FOR(i,0,N) cout << r[i] << endl;
    return 0;
}
