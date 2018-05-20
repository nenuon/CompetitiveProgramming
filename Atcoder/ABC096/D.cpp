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
// エラトステネスの篩O(NloglogN?)
const ll MAX = 100005;
bool isPrime[MAX];
vector<int> prime;
void makePrime(){
  for (ll i = 0; i < MAX; i++) isPrime[i] = true;
  for (ll i = 2; i * i < MAX + 1; i++){
    if(isPrime[i]){
      for (ll j = 2 * i; j < MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }
  for(int i = 2; i < MAX; i++) if(isPrime[i]) prime.push_back(i);
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;cin>>N;
  makePrime();
  int cnt=0,i=0;
  vector<int> ans;
  while(cnt<N&&i<prime.size()){
    if(prime[i]%5==1){
      ans.push_back(prime[i]);
      cnt++;
    }
    i++;
  }
  cout<<ans.size()<<endl;
  FOR(i,0,ans.size()){
    if(i)cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
}