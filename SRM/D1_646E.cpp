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

class TheConsecutiveIntegersDivOne {
    public:
    int find(vector<int> numbers, int k) {
        int n=numbers.size();
        sort(numbers.begin(),numbers.end());
        int ans=2e9;
        // 連続区間
        for(int i=0;i<n&&i+k-1<n;i++){
            //ajに合わせる
            FOR(j,i,i+k){
                int cnt=0;
                FOR(l,0,k){
                    cnt+=abs(numbers[i+l]-(numbers[j]-(j-i-l)));
                }
                ans=min(ans,cnt);
            }
        }
        return ans;
    }
};
