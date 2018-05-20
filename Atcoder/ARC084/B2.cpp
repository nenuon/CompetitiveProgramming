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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int K;
bool vis[100005];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> K;
  deque<pair<int, int> > Q;
  Q.push_back({1, 1});
  while(!Q.empty()) {
    auto top = Q.front(); Q.pop_front();
    int v = top.first;
    int cost = top.second;
    if(vis[v]) continue;
    vis[v] = true;
    if(v == 0) {
      cout << cost << endl;
      break;
    }
    Q.push_back({(v + 1) % K, cost + 1});
    Q.push_front({(v * 10) % K, cost});
  }
  return 0;
}