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
#define FOR(I, A, B) for (int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
typedef pair<ll, ll> P;
// 答え見た
// 最小値 * A >= 最大値になるまでは愚直にシミュレーション
// そのあとは周期的になる
const int mod = 1000000007;
int main()
{
    int N;
    cin >> N;
    ll A, B;
    cin >> A >> B;
    ll a[N], b[N]; CLR(b);
    FOR(i,0,N) cin >> a[i];
    sort(a, a + N);
    if(A == 1) {
      FOR(i,0,N) cout << a[i] << endl;
      return 0;
    }
    while(B) {
      sort(a, a + N);
      if(a[0]*A>=a[N-1]) break;
      a[0] *= A;
      B--;
    }
    sort(a, a + N);
    for (int i = 0; i < N; i++)
    {
        b[i] += B / N;
        b[i] += i < B % N ? 1 : 0;
    }
    FOR(i, 0, N)
    {
        ll x = A % mod;
        FOR(j, 0, log2(b[i])+10)
        {
            if ((b[i] >> j) & 1)
            {
                a[i] *= x;
                a[i] %= mod;
            }
            x *= x;
            x %= mod;
        }
    }
    FOR(i, 0, N)
    {
        int j = i + B % N;
        j %= N;
        cout << a[j] << endl;
    }
    return 0;
}
