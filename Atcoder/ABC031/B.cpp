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
    int L,H,N;//L*N分の運動が必要
    cin>>L>>H>>N;
    FOR(i, 0, N){
        int in;cin>>in;
        if(in>H) cout << -1 << endl;
        else if(in<L) cout << L-in << endl;
        else cout << 0 << endl;
    }
}
