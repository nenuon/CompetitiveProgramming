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
typedef pair<int, int> P;
map<P,vector<int> > MAP; // 同じ会社で行けるところ
map<P,int> dis; // 駅i会社jまでの距離
set<int> kaisatu[100005]; // 駅iから乗れる会社
// 会社変える->改札入るイメージ、コスト1かかる
// 0-1BFS->deque
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  //std::ifstream in("in/05.txt");
  //std::cin.rdbuf(in.rdbuf());
  int N,M;
  cin>>N>>M;
  FOR(i,0,M){
    int p,q,c;
    cin>>p>>q>>c;
    MAP[P(p,c)].push_back(q);
    MAP[P(q,c)].push_back(p);
    kaisatu[p].insert(c); // 駅pから乗れる会社
    kaisatu[q].insert(c); // 駅qから乗れる会社
  }
  deque<P> deq;
  dis[P(1,0)]=0;
  deq.push_front(P(1,0));
  while(deq.size()>0){
    P p=deq.front();
    deq.pop_front();
    int d=dis[p];
    int st=p.first;
    int com=p.second;
    //cout<<st<<" "<<com<<" "<<d<<endl;
    if(st==N){
      cout<<dis[p]<<endl;
      return 0;
    }
    // 改札にいる場合、乗り換え
    if(com==0){
      for(int ch : kaisatu[st]){
        if(dis.count(P(st,ch))==0||dis[P(st,ch)]>d+1){
          dis[P(st,ch)]=d+1;
          deq.push_back(P(st,ch));
        }
      }
    }else{
      // 同じ会社
      for(int to : MAP[p]){
        if(dis.count(P(to,com))==0||dis[P(to,com)]>d){
          dis[P(to,com)]=d;
          deq.push_front(P(to,com));
        }
      }
      // 改札にいく
      if(dis.count(P(st,0))==0||dis[P(st,0)]>d){
        dis[P(st,0)]=d;
        deq.push_front(P(st,0));
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}