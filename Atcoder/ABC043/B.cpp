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
    stack<char> sc;
    string s;
    cin>>s;
    FOR(i, 0, s.length()){
        if(s[i]!='B') sc.push(s[i]);
        else if(!sc.empty()) sc.pop();
    }
    string ans;
    while(!sc.empty()){
        ans.push_back(sc.top());
        sc.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
