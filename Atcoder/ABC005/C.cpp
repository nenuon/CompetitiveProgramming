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
    int T;
    cin >> T;

    int N;
    cin >> N;
    vector<int> A(N, 0);
    FOR(i, 0, N) cin >> A[i];

    int M;
    cin >> M;
    vector<int> B(M, 0);
    FOR(i, 0, M) cin >> B[i];

    if(N<M){
        cout << "no" << endl;
        return 0;
    }

    FOR(i, 0, N){
        FOR(j, 0, B.size()){
            int sa = B[j] - A[i];
            int check = 0;
            FOR(k, 0, T+1){
                if(sa == k){
                    B.erase(B.begin()+j);
                    check = 1;
                    break;
                }
            }
            if(check) break;
        }
    }

    if(B.size()==0) cout << "yes" << endl;
    else cout << "no" << endl;
}