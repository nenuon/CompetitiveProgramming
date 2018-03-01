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
// Xに含まれないやつは絶対作れる
// Xに含まれるやつ作れるかどうか調べればOK
class AmebaDiv1 {
public:
  int count(vector <int> X) {
    int n = X.size();
    map<int, bool> MAP;
    FOR(i,0,n) MAP[X[i]] = false; // xが作れるかどうか
    int ans = MAP.size();
    for(auto m : MAP) {
      int st = m.first;
      FOR(j,i,n) {
        if(st == X[j]) st *= 2;
      }
      if(MAP.count(st)) MAP[st] = true;
    }
    for(auto m : MAP) {
      ans -= m.second;
    }
    return ans;
  }
};
