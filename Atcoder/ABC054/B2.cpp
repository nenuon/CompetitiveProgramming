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
    int N, M;
    cin>>N>>M;
    vector<string> A, B;
    FOR(i, 0, N){
        string s;
        cin>>s;
        A.push_back(s);
    }
    FOR(i, 0, M){
      string s;
      cin>>s;
      B.push_back(s);
    }
    FOR(yi, 0, N-M+1){
        FOR(xi, 0, N-M+1){
            int check = 0;
            FOR(j, yi, M+yi){
                if(j<0 || j>N) break;
                FOR(k, xi, M+xi){
                    if(k<0 || k>N) break;
                    if(A[j][k]==B[j-yi][k-xi]) check++;
                }
            }
            if(check==M*M){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
