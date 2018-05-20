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
int INF = 99999999;
int color[100000];

void dijkstra(int s, int dd, int c){
    priority_queue<P, vector<P>, greater<P> > que;
    map<int, int> d;
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;
        if(d.count(v)==0) d[v] = INF;
        if(d[v] <= dd) color[v] = c;
        if(d[v] < p.first) continue;
        if(d[v] >= dd) continue;
        FOR(i, 0, G[v].size()){
            edge e = G[v][i];
            if(d.count(e.to)==0) d[e.to] = INF;
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
        scanf("%d %d", &a, &b);
        a--;b--;
        edge in;
        in.to = b;in.cost=1;
        G[a].push_back(in);
        in.to = a;in.cost=1;
        G[b].push_back(in);
    }
    int Q;
    cin>>Q;
    FOR(i, 0, N) color[i] = 0;
    FOR(i, 0, Q){
        int v, dd, c;
        scanf("%d %d %d", &v, &dd, &c);
        v--;
        dijkstra(v,dd,c);
    }
    FOR(i, 0, N) printf("%d\n",color[i]);
}
