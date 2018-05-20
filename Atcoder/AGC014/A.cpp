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
    ll a, b , c;
    cin >> a >> b >> c;
    if(a%2 || b%2 || c%2){
        cout << 0 << endl;
        return 0;
    }
    if(a==b && b==c){
        cout << -1 << endl;
        return 0;
    }
    ll ta = a, tb = b, tc = c;
    FOR(i,0,500000000){
        if(a%2 || b%2 || c%2){
            cout << i << endl;
            return 0;
        }
        a = (tb+tc)/2;
        b = (ta+tc)/2;
        c = (tb+ta)/2;
        ta = a, tb = b, tc = c;
    }
    cout << -1 << endl;
}
