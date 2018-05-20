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
    string s;
    int k;
    cin>>s>>k;
    map<string, int> MAP;
    int ans = 0;
    for(int i=0;i+k<=s.length();++i){
        string ss = s.substr(i, k);
        if(MAP.count(ss)==0){
            ans++;
            MAP[ss] = 1;
        }
    }
    cout << ans << endl;
}
