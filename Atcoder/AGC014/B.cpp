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
    cin >> N >> M;
    int cnt[N];
    FOR(i,0,N) cnt[i] = 0;
    FOR(i,0,M){
        int a, b;
        cin >> a >> b;
        a--;b--;
        cnt[a]++;cnt[b]++;
    }
    FOR(i,0,N){
        if(cnt[i]%2==1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
