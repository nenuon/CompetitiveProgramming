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
    int n, m, Y, Z;
    cin >> n >> m >> Y >> Z;cin.ignore();
    vector<string> c;
    int p[m];
    FOR(i, 0, m){
        string s;
        cin >> s;
        c.pb(s);
        cin >> p[i];
    }
    string st;
    getline(cin, st);

    int dp[n+1][1<<m][m];
    int INF = -9999999;
    FOR(i, 0, n){
        FOR(j, 0, 1<<m){
            FOR(k, 0, m){
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    //今注目しているブロックをtとする
    FOR(t, 0, n){
        int num = 0;
        FOR(i, 0, m){
            if(c[i] == st(t)){
                num = i;
                break;
            }
        }

        FOR(i, 0, 1<<m){
            FOR(j, 0, m){
                if(dp[t][i][j]==INF) continue;
                //捨てた時
                dp[t+1][i][j] = max(dp[t+1][i][j], dp[t][i][j]);

                //積み上げた時
                int nexti = i | (1<<num);
                int nextpoint = dp[t][i][j];
                //色ボーナス
                nextpoint += p[num];
                //コンボ(最初i=0は足さないことに注意)
                if(i!=0 && j==num) nextpoint += Y;

                dp[t+1][nexti][num] = max(dp[t+1][nexti][num], nextpoint);
            }
        }
    }

    int ret = 0;
    //全色ボーナスなし
    FOR(i, 0, (1<<m) - 1){
        FOR(j, 0, m){
            if(dp[n][i][j]==INF) continue;
            ret = max(ret, dp[n][i][j]);
        }
    }
    //あり
    FOR(j, 0, m){
        if(dp[n][(1<<m)-1][j]==INF) continue;
        ret = max(ret, dp[n][(1<<m)-1][j] + Z);
    }
    cout << ret << endl;
}