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
//全探索
int main(){
    int N;
    cin>>N;
    vector<string> vs;
    FOR(i, 0, N){
        string s;
        cin>>s;
        vs.push_back(s);
    }
    FOR(col, 0, N){
        for(int row=N-1; row>=0; --row){
            cout << vs[row][col];
        }
        cout << endl;
    }
}
