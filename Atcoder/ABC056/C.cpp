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
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

//Xを超えるか等しくなるまで足していく回数
//超えたら超えないように一回どこかで待つと考える

int main(void){
    ll X;
    cin>>X;
    ll i = 1;
    ll sum = 0;
    int ans = 0;
    while(X>sum){
        sum += i;
        i++;
        ans++;
    }
    cout<<ans<<endl;

}
