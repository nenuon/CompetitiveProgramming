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

class TheKingsFactorization {
    public:
    vector<long long> getVector(long long N, vector<long long> primes) {
        vector<ll> ans;
        int n=primes.size();
        FOR(i,0,n){
            while(N%primes[i]==0){
                N/=primes[i];
                ans.push_back(primes[i]);
            }
        }
        ll NN = N;
        FOR(i,2,min(primes[n-1],(ll)sqrt(NN))+1){
            while(N%i==0){
                N/=i;
                ans.push_back(i);
            }
        }
        if(N>1)ans.push_back(N);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
