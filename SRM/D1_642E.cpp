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
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
typedef pair<int, int> P;
double dp[200005];
class WaitingForBus {
    public:
    double whenWillBusArrive(vector<int> time, vector<int> prob, int s) {
        dp[0]=1.0;
        int n=time.size();
        FOR(i,0,s){
            FOR(j,0,n){
                dp[i+time[j]]+=dp[i]*prob[j]/100;
            }
        }
        double ans=0.0;
        FOR(i,s,200005){
            ans+=dp[i]*(i-s);
        }
        return ans;
    }
};
