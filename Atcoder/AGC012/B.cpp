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

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

struct edge {int to, cost; };
typedef pair<int, int> P;
int N, M;
vector<edge> G[100000];
int d[100000];
int INF = 99999999;

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+N, INF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        FOR(i, 0, G[v].size()){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    cin>>N>>M;
    FOR(i, 0, M){
        int a, b;
        cin>>a>>b;
        a--;b--;
        edge in;
        in.to = b;in.cost=1;
        G[a].push_back(in);
        in.to = a;in.cost=1;
        G[b].push_back(in);
    }
    int Q;
    cin>>Q;
    int color[N];
    FOR(i, 0, N) color[i] = 0;
    FOR(i, 0, Q){
        int v, dd, c;
        cin>>v>>dd>>c;
        v--;
        dijkstra(v);
        FOR(j, 0, N){
            if(d[j]<=dd) color[j] = c;
        }
    }
    FOR(i, 0, N){
        cout << color[i] << endl;
    }

}
