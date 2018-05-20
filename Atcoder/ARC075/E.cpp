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
using namespace std;

#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

typedef long long ll;

//////////////////////////////////////BIT 1 ~ n
struct BIT{
    vector<ll> data;
    int n;
    // 最大値求めたいとき最初は0を入れておく？
    // データはaddで随時追加してもいいし最初に全部入れても良い問題による
    BIT(int n) : data(n + 1, 0), n(n){
        return;
    }
    ll sum(int l, int r){
        return sum_(r) - sum_(l);
    }
    ll sum_(int i){
        ll res = 0;
        while(i > 0){
            res += data[i];
            i -= i & -i;
        }
        return res;
    }
    void add(int i, int x){
        while(i <= n){
            data[i] += x;
            i += i & -i;
        }
        return;
    }
};

ll a[200020]; // 累積和

int main(){
    ll n, k;
    cin >> n >> k;
    a[0] = 0;
    FOR(i,1,n+1){
        cin >> a[i];
        a[i] -= k; // 平均を引いておっく
        a[i] += a[i-1]; // 累積和
    }

    // 圧縮 小さい方から1,2,3...

    vector<int> ind(n+1);
    FOR(i,0,n+1) ind[i] = i;
    sort(ind.begin(), ind.end(), [](int i, int j){
        return a[i] < a[j];
    });
    ll bef = a[ind[0]];
    a[ind[0]] = 1;
    int j = 1;
    FOR(i,1,n+1){
        if(a[ind[i]]>bef){
            bef = a[ind[i]];
            j++;
            a[ind[i]] = j;
        }
        else a[ind[i]] = j;
    }
    /*
    vector<ll> vx;
    FOR(i,0,n+1) vx.push_back(a[i]);
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    */
    // BIT 0 ~ n
    ll ans = 0;
    BIT S(200020);
    FOR(i,0,n+1){
        //int pos = lower_bound(vx.begin(), vx.end(), a[i]) - vx.begin() + 1;
        int pos = a[i];
        ans += S.sum(0,pos);
        S.add(pos,1);
    }
    cout << ans << endl;
    return 0;
}
