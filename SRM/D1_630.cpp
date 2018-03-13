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
struct edge{
  int to, cost;
  edge(int t, int c) {
    to = t, cost = c;
  }
};
vector<edge> G[55];
int dis[55][55];
void dfs(int v, int p, int top, int len) {
    dis[top][v] = dis[top][p] + len;
    for(auto to : G[v]) {
        if(to.to == p || dis[top][to.to] != -1) continue;
        dfs(to.to, v, top, to.cost);
    }
}

class Egalitarianism3 {
    public:
    int maxCities(int n, vector<int> a, vector<int> b, vector<int> len) {
        if(n <= 2) return n;
        FOR(i,0,n-1) {
            a[i]--;b[i]--;
            G[a[i]].push_back(edge(b[i], len[i]));
            G[b[i]].push_back(edge(a[i], len[i]));
        }
        FOR(i,0,n) {
            FOR(j,0,n) {
                dis[i][j] = -1;
            }
        }
        FOR(i,0,n) {
            dis[i][i] = 0;
            dfs(i,i,i,0);
        }
        int ans = 2;
        // i中心
        FOR(i,0,n) {
            FOR(j,0,n) {
                int d = dis[i][j]; // 中心iから距離がdになる集合を求める
                vector<int> v;
                FOR(k,0,n) {
                    if(i == k) continue;
                    if(dis[i][k] == d) {
                        v.push_back(k);
                    }
                }
                int cnt = v.size();
                bool del[55];
                CLR(del);
                FOR(k,0,v.size()) {
                    FOR(l,k+1,v.size()) {
                        if(!del[v[l]] && dis[v[k]][v[l]] != 2 * d) {
                            cnt--;
                            del[v[l]] = true;
                        }
                    }
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
