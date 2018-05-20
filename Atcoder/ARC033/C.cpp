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
//////////////////////////////////////BIT
struct BIT{
  vector<ll> data;
  int n;
  // 最大値求めたいとき最初は0を入れておく？
  // データはaddで随時追加してもいいし最初に全部入れても良い問題による
  BIT(int n) : data(n + 1, 0), n(n){return;}
  ll sum(int l, int r){return sum_(r) - sum_(l);}
  ll sum_(int i){
    ll res = 0;
    while(i > 0){res += data[i];i -= i & -i;}
    return res;
  }
  void add(int i, int x){
    while(i <= n){data[i] += x;i += i & -i;}
    return;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int Q; cin >> Q;
  BIT B(200000);
  FOR(i,0,Q) {
    int t, x; cin >> t >> x;
    if(t == 1) B.add(x, 1);
    else {
      int l = 0, r = 200001;
      while(r - l > 1) {
        int med = (r + l) / 2;
        if(B.sum_(med) < x) l = med;
        else r = med;
      }
      cout << r << endl;
      B.add(r, -1);
    }
  }
  return 0;
}
