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
  int N;cin>>N;
  vector<int> ans;
  if(N==3){
    cout<<"2 5 63"<<endl;
  }else if(N==4){
    cout<<"2 5 20 63"<<endl;
  }else if(N==5){
    cout<<"2 5 20 30 63"<<endl;
  }else{
    int cnt=0;
    int sum=0;
    int a,b;
    for(int i=2;i<=30001;i++){
      if(cnt<N&&(i%2==0||i%3==0)){
        sum+=i;
        cnt++;
        ans.push_back(i);
      }
      if(i%6==0)a=i;
      if(i%6==4)b=i;
    }
    if(sum%6==2)ans[4]=a;
    if(sum%6==3)ans[5]=a;
    if(sum%6==5)ans[5]=b;
    FOR(i,0,N){
      if(i)cout<<" ";
      cout<<ans[i];
    }
    cout<<endl;
  }
  return 0;
}