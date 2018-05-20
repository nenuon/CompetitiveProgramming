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
    int N;
    string s;
    cin>>N>>s;
    int xmax = 0;
    int x = 0;
    FOR(i, 0, N){
        if(s[i]=='I') x++;
        else if(s[i]=='D') x--;
        xmax = max(xmax,x);
    }
    cout << xmax << endl;
}
