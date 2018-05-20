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
    string s;
    cin >> s;
    ll ans = 0;
    int len = s.length();
    FOR(i,0,len){
        if(s[i]=='U'){
            ans += (len-(i+1)) + i * 2;
        }
        else{
            ans += i + (len-(i+1)) * 2;
        }
    }
    cout << ans << endl;
}
