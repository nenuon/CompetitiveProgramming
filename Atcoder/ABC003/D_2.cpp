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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

int main()
{
  int R, G, B;
  cin >> R >> G >> B;
  int ret = 1e9;
  FOR(i,-1000,1001) {
    int ans = 0;
    int j = i + G - 1;
    // 緑
    FOR(k,i,j+1) {
      ans += abs(k-0);
    }

    // 赤
    bool left = false;
    int rl = -99, rr = -100;
    if(i <= -100) {
      rl = i;
      left = true;
    }
    FOR(k,0,R) {
      // 左にしか行けない場合
      if(left) {
        rl--;
        ans += abs(rl + 100);
      } else {
        // 左に行く
        if(k % 2 == 0) {
          rl--;
          ans += abs(rl + 100);
        } else { // 右に行きたい
          rr++;
          // 右に行けない
          if(rr == i) {
            left = true;
            rl--;
            ans += abs(rl + 100);
          } else { // 右に行ける
            ans += abs(rr + 100);
          }
        }
      }
    }

    // 青
    left = false;
    rl = 100, rr = 99;
    if(j >= 100) {
      rr = j;
      left = true;
    }
    FOR(k,0,B) {
      // 右にしか行けない場合
      if(left) {
        rr++;
        ans += abs(rr - 100);
      } else {
        // 右に行く
        if(k % 2 == 0) {
          rr++;
          ans += abs(rr - 100);
        } else { // 左に行きたい
          rl--;
          // 左に行けない
          if(rl == j) {
            left = true;
            rr++;
            ans += abs(rr - 100);
          } else { // 左に行ける
            ans += abs(rl - 100);
          }
        }
      }
    }
    ret = min(ret, ans);
  }
  cout << ret << endl;
  return 0;
}
