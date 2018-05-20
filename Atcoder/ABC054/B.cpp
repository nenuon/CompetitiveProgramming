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

#define pb         push_back
#define mp         make_pair
#define ll         long long
#define PI         acos(-1.0)
#define ALL(A)     ((A).begin(), (A).end())
#define vsort(v)   sort(v.begin(),v.end())
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    int N, M;
    cin >> N >> M;cin.ignore();
    vector<string> A, B;
    FOR(i, 0, N){
        string s;
        getline(cin, s);
        A.pb(s);
    }
    FOR(i, 0, M){
        string s;
        getline(cin, s);
        B.pb(s);
    }

    FOR(i, 0, N-M+1){
        FOR(j, 0, N-M+1){
            int check = 0;
            FOR(k, 0, M){
                FOR(l, 0, M){
                    if(B[k][l]==A[i+k][j+l]) check++;
                }
            }
            if(check == M*M){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}