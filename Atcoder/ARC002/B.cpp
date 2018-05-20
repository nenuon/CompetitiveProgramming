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
  int y, m, d;
  scanf("%d/%d/%d",&y,&m,&d);
  for(;;) {
    if(y % (m * d) == 0) {
      printf("%d/%02d/%02d\n",y,m,d);
      return 0;
    }
    d++;
    if(m == 2) {
      if(y % 4 == 0) {
        if(y % 100 == 0 && y % 400 != 0) {
          if(d == 29) {
            m++;
            d = 1;
          }
        } else {
          if(d == 30) {
            m++;
            d = 1;
          }
        }
      } else {
        if(d == 29) {
          m++;
          d = 1;
        }
      }
    } else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
      if(d == 32) {
        m++;
        d = 1;
      }
    } else {
      if(d == 31) {
        m++;
        d = 1;
      }
    }
    if(m == 13) {
      y++;
      m = 1;
    }
  }
}
