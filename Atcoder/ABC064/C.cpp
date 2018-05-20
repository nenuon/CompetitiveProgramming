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
    int rate[8], any = 0;
    FOR(i,0,8) rate[i] = 0;
    FOR(i,0,n){
        int in;
        cin >> in;
        if(in>=3200) any++;
        else rate[in/400]++;
    }
    int MIN = 0 ,MAX;
    FOR(i,0,8) if(rate[i] != 0) MIN++;
    MAX = MIN + any;
    if(MIN == 0) MIN = 1;
    cout << MIN << " " << MAX << endl;
}
