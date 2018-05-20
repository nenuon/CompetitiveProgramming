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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S, T;
  cin >> S >> T;
  int slen = S.length();
  int tlen = T.length();
  int SA[slen+1], SB[slen+1];
  int TA[tlen+1], TB[tlen+1];
  A[0] = B[0] = 0;
  FOR(i,0,slen) SA[i+1] = SA[i] + (s[i] == 'A');
  FOR(i,0,slen) SB[i+1] = SB[i] + (s[i] == 'B');
  FOR(i,0,tlen) TA[i+1] = TA[i] + (t[i] == 'A');
  FOR(i,0,tlen) TB[i+1] = TB[i] + (t[i] == 'B');
  int q; cin >> q;
  FOR(i,0,q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sa = (SA[b+1] - SA[a]) % 3; // Aの数
    int sb = (SB[b+1] - SB[a]) % 3; // Bの数
    int ta = (TA[d+1] - TA[c]) % 3; // Aの数
    int tb = (TB[d+1] - TB[c]) % 3; // Bの数
    int check_a, check_b;
    if(sa == sb) check_a = 0;
    if(sa == 2 && sb == 1) check_a = 1;
    if(sa == 0 && sb == 2) check_a = 1;
    if(sa == 1 && sb == 0) check_a = 1;
    if(sa == 1 && sb == 2) check_a = 2;
    if(sa == 2 && sb == 0) check_a = 2;
    if(sa == 0 && sb == 1) check_a = 2;
    if(ta == tb) check_b = 0;
    if(ta == 2 && tb == 1) check_b = 1;
    if(ta == 0 && tb == 2) check_b = 1;
    if(ta == 1 && tb == 0) check_b = 1;
    if(ta == 1 && tb == 2) check_b = 2;
    if(ta == 2 && tb == 0) check_b = 2;
    if(ta == 0 && tb == 1) check_b = 2;
    cout << (check_a == check_b ? "YES" : "NO") << endl;
  }
}