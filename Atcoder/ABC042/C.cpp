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
    int K;
    cin>>N>>K;
    bool D[10];//嫌な数字ならtrue
    FOR(i, 0, 10) D[i] = false;
    FOR(i, 0, K){
        int d;
        cin>>d;
        D[d] = true;
    }
    //全探索
     FOR(i, 0, 10*N){
        if(N<=i){
            int check = true;
            string s = to_string(i);
            FOR(j, 0, s.length()){
                if(D[s[j]-'0']) check = false;
            }
            if(check){
                cout << i << endl;
                return 0;
            }
        }
     }
}
