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
const ll MAX = 100005;
bool isPrime[MAX];
void makePrime(){
  for (ll i = 2; i < MAX; i++) isPrime[i] = true;
  for (ll i = 2; i * i < MAX + 1; i++){
    if(isPrime[i]){
      for (ll j = 2 * i; j < MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }
  return;
}
bool memo[100005];
int MEMO[100005];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  makePrime();
  FOR(i,1,100005) {
    if(i & 1) {
      memo[i] = isPrime[i] && isPrime[(i + 1) / 2];
    }
  }

  FOR(i,1,100005) {
    MEMO[i] = MEMO[i-1] + memo[i];
  }

  int Q; cin >> Q;
  FOR(i,0,Q) {
    int l, r; cin >> l >> r;
    cout << MEMO[r] - MEMO[l-1] << endl;
  }
  return 0;
}
