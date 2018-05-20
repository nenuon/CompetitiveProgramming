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
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H,W;cin>>H>>W;
  vector<string> vs(H);
  FOR(i,0,H)cin>>vs[i];
  bool ok[H][W];
  CLR(ok);
  // tate
  FOR(y,0,H-1){
    FOR(x,0,W){
      if(vs[y][x]=='#'&&vs[y+1][x]=='#'){
        ok[y][x]=ok[y+1][x]=true;
      }
    }
  }
  // yoko
  FOR(y,0,H){
    FOR(x,0,W-1){
      if(vs[y][x]=='#'&&vs[y][x+1]=='#'){
        ok[y][x]=ok[y][x+1]=true;
      }
    }
  }
  FOR(y,0,H){
    FOR(x,0,W){
      if(vs[y][x]=='#'){
        if(!ok[y][x]){
          cout<<"No"<<endl;
          return 0;
        }
      }
    }
  }
  cout<<"Yes"<<endl;
}