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
const int MOD=1e9+7;
typedef pair<int, char> P;
class TaroFillingAStringDiv1 {
    public:
    int getNumber(int N, vector<int> position, string value) {
        vector<P> v;
        int M=position.size();
        FOR(i,0,M)v.push_back(P(position[i],value[i]));
        sort(v.begin(),v.end());
        ll ans=1;
        FOR(i,0,M-1){
            int d=v[i+1].first-v[i].first-1;
            char x=v[i].second,y=v[i+1].second;
            if(x==y){
                if(d%2==0){
                    ans*=d+1;
                    ans%=MOD;
                }
            }else{
                if(d%2==1){
                    ans*=d+1;
                    ans%=MOD;
                }
            }
        }
        
        return ans;
    }
};
