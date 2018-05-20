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
//b以下-a未満
int main(){
    ll a,b,x,ans;
    cin>>a>>b>>x;
    ans = b/x;
    if(a>0) ans -= (a-1)/x;
    else ans++;
    cout<<ans<<endl;
}
