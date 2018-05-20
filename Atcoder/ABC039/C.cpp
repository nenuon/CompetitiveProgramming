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
    cin >> s;
    vector< pair<string, string> > P;
    P.push_back(make_pair("WBWBWWBWBWBW", "Do"));
    P.push_back(make_pair("WBWWBWBWBWWB", "Re"));
    P.push_back(make_pair("WWBWBWBWWBWB", "Mi"));
    P.push_back(make_pair("WBWBWBWWBWBW", "Fa"));
    P.push_back(make_pair("WBWBWWBWBWWB", "So"));
    P.push_back(make_pair("WBWWBWBWWBWB", "La"));
    P.push_back(make_pair("WWBWBWWBWBWB", "Si"));
    int j = 0;
    while(1){
        int cnt = 0;
        FOR(i, 0, P[j].first.length()){
            if(s[i]==P[j].first[i]) cnt++;
        }
        if(cnt==P[j].first.length()){
            cout << P[j].second << endl;
            return 0;
        }
        j++;
    }
}
