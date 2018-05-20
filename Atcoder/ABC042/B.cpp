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
    int N,L;
    cin>>N>>L;
    vector<string> all;
    string s;
    FOR(i, 0, N){
        cin>>s;
        all.push_back(s);
    }
    sort(all.begin(), all.end());
    FOR(i, 0, N){
        cout << all[i];
    }
    cout << endl;
}
