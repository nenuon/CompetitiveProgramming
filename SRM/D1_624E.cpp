#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
using namespace std;
typedef long long ll;
class BuildingHeights {
    public:
    int minimum(vector<int> heights) {
        sort(heights.begin(), heights.end());
        int n = heights.size();
        int sum[4004];
        sum[0] = 0;
        FOR(i,0,n) sum[i+1] = sum[i] + heights[i];
        int ans = 0;
        // j...i(max)
        FOR(num,1,n+1) {
            int mn = 1e9;
            for(int i = n - 1; i >= 0; i--) {
                int j = i + 1 - num;
                if(j < 0) break;
                mn = min(mn, num * heights[i] - sum[i+1] + sum[j]);
            }
            ans ^= mn;
        }
        return ans;
    }
};
