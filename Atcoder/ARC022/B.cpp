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
int A[100005]; 
bool use[100005]; 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  FOR(i,0,N) cin >> A[i];
  int l = 0, r = 0;
  int ans = 0;
  while(r < N && l < N) {
    if(use[A[r]]) {
      while(A[l] != A[r]) {
        use[A[l]] = false;
        l++;
      }
      use[A[l]] = false;
      l++;
      ans = max(ans, r - l + 1);
    } else {
      use[A[r]] = true;
      ans = max(ans, r - l + 1);
      r++;
    }
  }
  cout << ans << endl;
  return 0;
}