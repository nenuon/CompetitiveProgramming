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
#include <random>
#include <fstream>
#include <time.h>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;

/*
ソートの速度比較
*/
const int N = 10000;
vector<int> vec;
void init(int n){
  vec.resize(n);
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand(-1000000000, 1000000000);
  FOR(i,0,N) vec[i] = rand(mt);
}

void check(vector<int> v){
  FOR(i,0,N-1){
    if(v[i]>v[i+1]){
      cout<<"NOOOOOOOOOOOOOOOO"<<endl;
      return;
    }
  }
  cout<<"OK"<<endl;
}


clock_t start;
void startTime(){
  start = clock();
}
void endTime(){
  clock_t end = clock();
  cout << (double)(end - start) / CLOCKS_PER_SEC << endl;  
}

// 挿入ソート
void Insertion(vector<int> v){
  cout<<"Insertion start"<<endl;
  FOR(i,1,N){
    int x = v[i];
    int j = i - 1;
    while(j >= 0 && v[j] > x){
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = x;
  }
  //check(v);
}

void Bubble(vector<int> v){
  cout<<"Bubble start"<<endl;
  bool flag = true;
  while(flag) {
    flag = false;
    FOR(i,0,N-1){
      if(v[i] > v[i + 1]){
        swap(v[i], v[i+1]);
        flag = true;
      }
    }
  }
  //check(v);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  init(N);
  
  startTime();
  Insertion(vec);
  endTime();

  startTime();
  Bubble(vec);
  endTime();
}
