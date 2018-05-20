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

//bit使わなくても+の時は答えにたす、そうでなければためてある数を10倍して新しい数たす
//というのを繰り返せば良い

ll strtoll(string s){
    ll ret = 0;
    FOR(i, 0, s.length()){
        ret += pow(10, s.length()-i-1) * (s[i]- '0');
    }
    return ret;
}

int main(void){
    string s;
    cin>>s;
    int N =s.length();
    vector<string> vs(N);
    ll ans = 0;
    FOR(i, 0, N) vs[i] = s[i];//1文字ずつ保存
    FOR(i, 0, 1<<(N-1)){
        vector<string> num;
        string ss = vs[0];
        FOR(j, 0, N-1){
            //bitが0の時
            if((i>>j)%2==0) ss += vs[j+1];
            //1の時
            else{
                num.push_back(ss);
                ss = vs[j+1];
            }
        }
        num.push_back(ss);
        FOR(i, 0, num.size()) ans += strtoll(num[i]);
    }
    cout << ans << endl;
}
