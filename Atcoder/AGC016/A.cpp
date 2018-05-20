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

int main(){
    string s;
    cin >> s;
    int len = s.length();
    vector<int> v;
    FOR(i,0,len) v.push_back(s[i]-'a');
    int ans = 1000;
    int check = v[0];
    bool ok = true;
    FOR(i,1,len) if(check != v[i]) ok = false;
    if(ok){
        cout << 0 << endl;
        return 0;
    }

    // iで揃える
    FOR(i,0,26){
        vector<int> tmp = v;
        int cnt = 0;
        int l = len;
        while(l>0){
            FOR(k,0,l-1) if(tmp[k+1] == i) tmp[k] = tmp[k+1];
            cnt++;
            bool ok1 = true;
            FOR(k,0,l-1) if(tmp[k] != i) ok1 = false;
            if(ok1){
                ans = min(ans, cnt);
                break;
            }
            l--;
        }
    }
    cout << ans << endl;
    return 0;
}
