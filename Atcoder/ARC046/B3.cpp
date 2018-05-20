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
void f() {cout << "Takahashi" << endl;}
void s() {cout << "Aoki" << endl;}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, A, B; cin >> N >> A >> B;
  if(N <= A) f();
  else {
    if(A > B) f();
    else if(A < B) s();
    else {
      if(N % (A + 1) == 0) s();
      else f();
    }
  }
  return 0;
}