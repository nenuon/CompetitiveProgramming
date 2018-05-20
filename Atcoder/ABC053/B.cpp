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
    string s;
    cin>>s;
    int a=999999, z=0;
    FOR(i, 0, s.length()){
        if(s[i]=='A') a = min(a, i);
        if(s[i]=='Z') z = max(z, i);
    }
    cout << z-a+1 << endl;
}
