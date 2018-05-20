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

//+で区切られているグループの中に0がなければans++

int main(){
    string s;
    cin>>s;
    bool comeon = true;
    int tasu = 0;
    int zeros = 0;
    FOR(i, 0, s.length()){
        if(s[i]=='+'){
            tasu++;
            comeon = true;
            continue;
        }
        if(comeon && s[i]=='0'){
            zeros++;
            comeon = false;
        }
    }
    cout << tasu+1 - zeros << endl;
}
