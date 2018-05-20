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
  string A, B;
  cin >> A >> B;
  if(A.length()>B.length()) {
    puts("GREATER");
  } else if(A.length()<B.length()) {
    puts("LESS");
  } else {
    FOR(i,0,A.length()) {
      if(A[i] - '0' > B[i] - '0') {
        puts("GREATER");
        return 0;
      }
      else if(B[i] - '0' > A[i] - '0') {
        puts("LESS");
        return 0;
      }
    }
    puts("EQUAL");
  }
  return 0;
}
