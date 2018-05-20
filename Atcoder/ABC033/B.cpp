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
    int N;
    cin>>N;
    vector<string> vs;
    vector<int> P(N);

    int sum = 0;
    FOR(i, 0, N){
        string s;
        cin>>s>>P[i];
        vs.push_back(s);
        sum += P[i];
    }
    FOR(i, 0, N){
        if(sum<P[i]*2){
            cout << vs[i] << endl;
            return 0;
        }
    }
    cout << "atcoder" << endl;
}
