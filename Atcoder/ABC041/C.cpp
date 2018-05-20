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

//pair使う

//身長, 出席番号
typedef pair<int, int> P;

int main(){
     int N;
     cin>>N;
    vector<P> vp(N);
    FOR(i, 0, N){
        int a;
        cin>>a;
        vp[i].first = a;
        vp[i].second = i+1;
    }
    sort(vp.rbegin(), vp.rend());
    FOR(i, 0, N) cout << vp[i].second << endl;
}
