^#include <algorithm>
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
string A;
int b[202020]; // i-1文字目以降で現れている文字の集合
int c[202020]; // i-1文字目以降で現れていない最小の文字 0->a,1->b...25->z
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A;
  int n = A.length();
  b[n] = 0;
  c[n] = 0;
  for(int i = n - 1; i >= 0; i--) {
    b[i] = b[i+1] | (1 << (A[i] - 'a'));
    c[i] = c[i+1];
    while(b[i] & (1 << c[i])) ++c[i];
    if(c[i] == 26) b[i] = c[i] = 0;
  }
  FOR(i,0,n) {
    char x = c[i] + 'a';
    cout << x;
    while(i < n && A[i] != x) ++i;
  }
  cout << endl;
  return 0;
}