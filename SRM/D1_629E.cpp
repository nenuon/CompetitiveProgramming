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

class RectangleCovering {
    public:
    int minimumNumber(int holeH, int holeW, vector<int> boardH, vector<int> boardW) {
        int n = boardH.size();
        int ans = 2e9;
        // H側に
        vector<int> v1(n);
        FOR(i,0,n) {
            int h = boardH[i] - holeH;
            int w = boardW[i] - holeH;
            if(h >= 1 && w >= 1) {
                if(h >= w) v1[i] = boardH[i];
                else v1[i] = boardW[i];
            }
            else if(h >= 1) v1[i] = boardW[i];
            else if(w >= 1) v1[i] = boardH[i];
            else v1[i] = 0;
        }
        sort(v1.rbegin(), v1.rend());
        int cnt = 0;
        FOR(i,0,n) {
            cnt += v1[i];
            if(cnt >= holeW) ans = min(ans, i + 1);
        }
        vector<int> v2(n);
        FOR(i,0,n) {
            int h = boardH[i] - holeW;
            int w = boardW[i] - holeW;
            if(h >= 1 && w >= 1) {
                if(h >= w) v2[i] = boardH[i];
                else v2[i] = boardW[i];
            }
            else if(h >= 1) v2[i] = boardW[i];
            else if(w >= 1) v2[i] = boardH[i];
            else v2[i] = 0;
        }
        sort(v2.rbegin(), v2.rend());
        cnt = 0;
        FOR(i,0,n) {
            cnt += v2[i];
            if(cnt >= holeH) ans = min(ans, i + 1);
        }

        //W側に
        return ans == 2e9 ? -1 : ans;
    }
};
