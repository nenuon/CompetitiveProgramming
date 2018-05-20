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
    cin.ignore();
    string st;
    getline(cin, st);

    int INF = -999999;
    int dp[n+1][1<<m][m];
    FOR(i, 0, n+1){
        FOR(j, 0, 1<<m){
            FOR(k, 0, m){
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;

    FOR(i, 0, n){
        int num = 0;
        FOR(t, 0, m){
            if(c[t][0] == st[i]){
                num = i;
                break;
            }
        }
        FOR(j, 0, 1<<m){
            FOR(k, 0, m){
                if(dp[i][j][k] == INF) continue;
                //not use
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);

                //use
                int nextj = j | (1<<num);
                int bounus = 0;
                //iro bounus
                bounus += p[num];
                //conbo
                if(i!=0 && num==k){
                    bounus += Y;
                }
                dp[i+1][nextj][num] = max(dp[i+1][nextj][num], dp[i][j][k]+bounus);   
            }
        }
    }

    int ans = 0;
    FOR(i, 0, (1<<m)-1){
        FOR(j, 0, m){
            if(dp[n][i][j] == INF) continue;
            ans = max(ans, dp[n][i][j]);
        }
    }

    FOR(i, 0, m){
        if(dp[n][(1<<m)-1][i] == INF) continue;
        ans = max(ans, dp[n][(1<<m)-1][i] + Z);
    }
    cout << ans << endl;
}