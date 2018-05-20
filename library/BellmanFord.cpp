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
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;

/*
ベルマンフォード
一対多の最短経路問題を解く
計算量O(EV)
負の辺がある場合E回以上の更新が行われるので負の辺の検出に用いることができる
*/

const int MAXE = 1000;
const int MAXV = 1000;
struct edge {
  int from;
  int to;
};
edge es[MAXE];
int d[MAXV];
int V, E;
void shortest_path(int s){
  for(int i=0;i<MAXV;i++) d[i]=1e9;
  d[s]=0;
  while(true){
    bool update=false;
    for(int i=0;i<E;i++){
      if(d[es[i].from]!=1e9&&d[es[i].to]>d[es[i].from]+es[i].to){
        d[es[i].to]=d[es[i].from]+es[i].to;
        update=true;
      }
    }
    if(!update)break;
  }
}