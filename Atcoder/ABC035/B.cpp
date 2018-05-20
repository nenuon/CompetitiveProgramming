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

string s;
int T;

int manhattan(int x, int y){
    return abs(x) + abs(y);
}

int main(){
    cin>>s>>T;
    int x = 0, y = 0;
    int hatena = 0;
    FOR(i, 0, s.length()){
        if(s[i]=='U') y++;
        else if(s[i]=='R') x++;
        else if(s[i]=='D') y--;
        else if(s[i]=='L') x--;
        else if(s[i]=='?') hatena++;
    }
    int ans = manhattan(x, y);
    if(T==1) ans += hatena;
    else{
        if(ans>hatena) ans -= hatena;
        //|S|%2でokだった
        else if((hatena-ans)%2==0) ans = 0;
        else if((hatena-ans)%2==1) ans = 1;
    }
    cout<<ans<<endl;
}
