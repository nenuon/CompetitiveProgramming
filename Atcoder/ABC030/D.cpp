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
int N, a;
string K;
int main()
{
  cin >> N >> a >> K;
  int b[N+1]; FOR(i,1,N+1) cin >> b[i];
  vector<int> num; num.push_back(a);
  FOR(i,1,3*N) num.push_back(b[num.back()]);
  if(K.length() <= log10(N) + 1) cout << num[stoi(K)] << '\n';
  // 絶対閉路に入っている
  else {
    // 閉路のながさ
    int c = 0;
    for(int i = (int)num.size() - 2; i >= 0; i--) {
      c++;
      if(num[i] == num.back()) break;
    }
    int m = 0;
    FOR(i,0,K.length()) {
      m *= 10;
      m += K[i] - '0';
      m %= c;
    }
    while(m < N) m += c;
    cout << num[m] << '\n';
  }
  return 0;
}
