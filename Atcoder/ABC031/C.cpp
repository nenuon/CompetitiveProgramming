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

//全探索でO(N^3)でできる
const int INF = -99999999;
int main(){
    int N;
    cin>>N;
    int a[N];
    FOR(i, 0, N) cin>>a[i];
    int maxpta = INF;
    FOR(ta, 0, N){
        int tmp_pao = INF, tmp_pta = INF;
        FOR(ao, 0, N){
            if(ta == ao) continue;
            int l = min(ta, ao), r = max(ta, ao);
            int pta = 0, pao = 0;
            FOR(i, l, r+1){
                if((i-l)%2 == 0) pta += a[i];
                else pao += a[i];
            }
            //青木くんの選択で青木くんのとれる最大値
            if(tmp_pao<pao){
                tmp_pao = pao;
                tmp_pta = pta;
            }
        }
        //高橋くんの選択で高橋くんがとれる最大値
        maxpta = max(maxpta, tmp_pta);
    }
    cout << maxpta << endl;
}
