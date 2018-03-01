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
class MinimumSquare {
  ll llabs(ll x) {return x > 0 ? x : -x;}
public:
  long long minArea(vector <int> x, vector <int> y, int K) {
    int n = x.size();
    vector<ll> v(n);
    FOR(i,0,n) v[i] = x[i];
    sort(v.begin(), v.end());
    ll ans = 1LL<<62;
    FOR(l,0,n) {
      FOR(r,l,n) {
        vector<ll> v2;
        v2.resize(0);
        FOR(i,0,n) {
          if(x[i] >= v[l] && x[i] <= v[r]) {
            v2.push_back(y[i]);
          }
        }
        if(v2.size() < K) continue;
        sort(v2.begin(), v2.end());
        for(int i = 0; i + K - 1 < v2.size(); i++) {
          ll mx = (ll)max(llabs(v[r]-v[l])+2, llabs(v2[i+K-1]-v2[i])+2);
          ans = min(ans, mx * mx);
        }
      }
    }
    FOR(i,0,n) v[i] = y[i];
    sort(v.begin(), v.end());
    FOR(l,0,n) {
      FOR(r,l,n) {
        vector<ll> v2;
        FOR(i,0,n) {
          if(y[i] >= v[l] && y[i] <= v[r]) {
            v2.push_back(x[i]);
          }
        }
        if(v2.size() < K) continue;
        sort(v2.begin(), v2.end());
        for(int i = 0; i + K - 1 < v2.size(); i++) {
          ll mx = (ll)max(llabs(v[r]-v[l])+2, llabs(v2[i+K-1]-v2[i])+2);
          ans = min(ans, mx * mx);
        }
      }
    }
    return ans;
  }
};
