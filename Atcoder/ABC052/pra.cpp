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
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(void){
  int N,Q,i,j;

  scanf("%d %d", &N, &Q);

  string s;
  for(i=0;i<N;i++) s += (char)('A' + i);

  for(i=0;i<N;i++) for(j=0;j<N-1;j++){
    printf("? %c %c\n", s[j], s[j+1]);
    fflush(stdout);
    char ans;
    scanf(" %c", &ans);
    if(ans == '>') swap(s[j], s[j+1]);
  }

  printf("! %s\n", s.c_str());
  fflush(stdout);

  return 0;
}
