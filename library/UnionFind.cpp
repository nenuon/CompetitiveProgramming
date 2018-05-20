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


/* unionfind tree
グループ分け

*/

struct UnionFind {
  vector<int> par;
  vector<int> rnk;
  int n;
  UnionFind(int n):n(n){
    par.resize(n);rnk.resize(n);
    for(int i=0; i<n; i++){par[i] = i;rnk[i] = 0;}
  }
  int find(int x){
      if(par[x] == x) return x;
      else return par[x] = find(par[x]);
  }
  void unite(int x, int y){
      x = find(x);y = find(y);
      if(x == y) return;
      if(rnk[x] < rnk[y])par[x] = y;
      else {
        par[y] = x;
        if(rnk[x] == rnk[y]) rnk[x]++;
      }
      return;
  }
  bool isSame(int x, int y){return find(x) == find(y);}
};