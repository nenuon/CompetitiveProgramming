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

using namespace std;

class BuildingRoutes {
    public:
    int build(vector<string> dist, int T) {
        int n = dist.size();
        // 最短経路求める
        int d[n][n];
        int mind[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d[i][j] = mind[i][j] = dist[i][j] - '0';
            }
        }
        for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            mind[i][j] = min(mind[i][j], mind[i][k] + mind[k][j]);
        }
        int cnt[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cnt[i][j] = 0;
            }
        }
        // i->jに行くのにk->lは使われているのか
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                for(int k = 0; k < n; k++) {
                    for(int l = 0; l < n; l++) {
                        if(k == l) continue;
                        if(mind[i][j] == mind[i][k] + d[k][l] + mind[l][j]) {
                            cnt[k][l]++;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int k = 0; k < n; k++) {
            for(int l = 0; l < n; l++) {
                if(k == l) continue;
                if(cnt[k][l] >= T) ans += d[k][l];
            }
        }
        return ans;
    }
};

