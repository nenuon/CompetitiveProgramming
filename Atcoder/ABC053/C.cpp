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
    ll x;
    cin>>x;
    ll ans;
    ans = x / 11;
    ans *= 2;
    if(x%11<=6 && x%11>0) ans++;
    else if(x%11>6) ans+=2;
    cout << ans << endl;
}
