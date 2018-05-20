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

//連続した白黒のグループの個数-1
//O(N)

int main(void){
    string s;
    cin>>s;
    char now = s[0];
    int ans = 1;
    FOR(i, 1, s.length()){
        if(s[i]==now) continue;
        now = s[i];
        ans++;
    }
    cout << ans - 1 << endl;
}
