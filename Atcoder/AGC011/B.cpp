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
    cin >> N;
    vector<double> A(N);
    FOR(i, 0, N) cin >> A[i];
    sort(A.begin(), A.end());
    ll ans = 1;
    FOR(i, 0, N-1){
        //どっちにもなれるなら色の可能性+1
        if(A[i+1] <= A[i] * 2){
            ans++;
        }
        //片方にしかなれないなら色の可能性は1になっちゃう
        else ans = 1;
        A[i+1] += A[i];
    }
    cout << ans << endl;
}
