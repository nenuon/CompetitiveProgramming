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

vector<int> par;
vector<int> rnk; 
void init(int n){
    par.resize(n);rnk.resize(n);
    FOR(i, 0, n){par[i] = i;rnk[i] = 0;}
}
int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}
void unite(int x, int y){
    x = find(x);y = find(y);
    if(x == y) return;
    if(rnk[x] < rnk[y])par[x] = y;
    else{par[y] = x;if(rnk[x] == rnk[y]) rnk[x]++;}
    return;
}
bool isSame(int x, int y){return find(x) == find(y);}

struct edge{
  int u, v, cost;
  edge(int a, int b, int c) {
    u=a,v=b,cost=c;
  }
};
// クラスカル法(最小全域木求めるやつ)
bool comp(edge e1, edge e2){
  return e1.cost < e2.cost;
}
vector<edge> es;
int kruskal(){
  sort(es.begin(), es.end(), comp);
  init(222);
  int res = 0;
  FOR(i,0,es.size()){
    edge e = es[i];
    if(!isSame(e.u, e.v)){
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

class ChristmasTreeDecoration {
    public:
    int solve(vector<int> col, vector<int> x, vector<int> y) {
        int n=x.size();
        FOR(i,0,n){
            if(col[x[i]-1]==col[y[i]-1])es.push_back(edge(x[i],y[i],1));
            else es.push_back(edge(x[i],y[i],0));
        }
        return kruskal();
    }
};
