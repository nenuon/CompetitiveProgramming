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
#include <bitset>
using namespace std;

#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int maxx = -1, minx = 99999;
    FOR(i,0,n){
        int in;
        cin >> in;
        maxx = max(maxx, in);
        minx = min(minx, in);
    }
    cout << maxx - minx << endl;
}
