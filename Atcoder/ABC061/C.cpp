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
int a[100010], b[100010];
int main(){
    int N;
    ll K;
    cin >> N >> K;
    vector<int> ind(N);

    FOR(i,0,N) ind[i] = i;
    FOR(i,0,N){
        cin >> a[i] >> b[i];
    }
    //小さい順
    sort(ind.begin(), ind.end(), [](int i, int j){
        return a[i] < a[j];
    });
    ll k = 0;
    int i = 0;
    while(1){
        if(k<K && K<=k+b[ind[i]]){
            cout << a[ind[i]] << endl;
            return 0;
        }
        k += b[ind[i]];
        i++;
    }
}
