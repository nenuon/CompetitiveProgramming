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
int N, K;
vector<string> num, goro;
int mojisu[10];
// 数字xが文字数k個に対応
void dfs(int x, int k) {
  mojisu[x] = k;
  if(x == K) {
    map<int, string> MAP;
    bool ok = true;
    FOR(i, 0, N) {
      int moji = 0;
      // 文字数が合わない場合 or ok=falseの場合 break
      FOR(j, 0, num[i].length()) moji += mojisu[num[i][j]-'0'];
      if(moji != goro[i].length() || !ok) {
        ok = false;
        break;
      }
      moji = 0;
      FOR(j, 0, num[i].size()) {
        // すでに決めている場合
        if(MAP.count(num[i][j] - '0')) {
          if(MAP[num[i][j] - '0'] != goro[i].substr(moji, mojisu[num[i][j] - '0'])) {
            ok = false;
            break;
          }
        } else {
          MAP[num[i][j] - '0'] = goro[i].substr(moji, mojisu[num[i][j] - '0']);
        }
        moji += mojisu[num[i][j] - '0'];
      }
    }
    if(ok) {
      for(auto m : MAP) {
        cout << m.second << endl;
      }
      exit(0);
    }
  } else {
    FOR(i, 1, 4) dfs(x + 1, i);
  }
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> K >> N;
  FOR(i, 0, N) {
    string v, w; cin >> v >> w;
    num.push_back(v);
    goro.push_back(w);
  }
  FOR(i, 1, 4) dfs(1, i);
  return 0;
}