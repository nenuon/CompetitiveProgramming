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
  int n; cin >> n;
  int a[n];
  int sum = 0;
  FOR(i,0,n) {
    scanf("%d",a+i);
    sum += a[i];
  }
  if(sum % n != 0) {
    puts("-1");
    return 0;
  }
  int ave = sum / n;
  int ans = 0;
  int num = 0;
  sum = 0;
  FOR(i,0,n) {
    sum += a[i];
    num++;
    if(sum % num == 0 && sum / num == ave) {
      ans += num - 1;
      num = 0;
      sum = 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}
