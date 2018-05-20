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
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
typedef pair<ll, int> P;
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
  int N, K; cin >> N >> K;
  int a[N];
  vector<ll> sum(N+1, 0), sortSum(N+1, 0);
  FOR(i,0,N) {
    cin >> a[i];
    a[i] -= K;
    sum[i+1] = sum[i] + a[i];
    sortSum[i+1] = sortSum[i] + a[i];
  }
  sort(sortSum.begin(), sortSum.end());
  BIT bit(202020);
  ll ans = 0;
  FOR(i,0,N+1) {
    int x = lower_bound(sortSum.begin(), sortSum.end(), sum[i]) - sortSum.begin();
    ans += bit.sum_(x+1);
    bit.add(x+1, 1);
  }
  cout << ans << endl;
  return 0;
}