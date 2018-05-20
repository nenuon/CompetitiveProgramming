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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  string s = "ABXY";
  string comand; cin >> comand;
  int ans = 1e5;
    FOR(a,0,4) {
      FOR(b,0,4) {
        FOR(c,0,4) {
          FOR(d,0,4) {
            int cnt = 0;
            int j = 0;
            while(j < N) {
              if(j == N - 1) {
                cnt++;
                break;
              }
              if(comand[j] == s[a] && comand[j+1] == s[b]) {
                cnt++;
                j += 2;
              } else if(comand[j] == s[c] && comand[j+1] == s[d]) {
                cnt++;
                j += 2;
              } else {
                cnt++;
                j++;
              }
            }
            ans = min(ans, cnt);
          }
        }
      }
    }
  cout << ans << endl;
  return 0;
}
