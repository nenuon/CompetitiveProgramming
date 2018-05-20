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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0;
    int r = 0;
    FOR(i,0,n){
        if(s[i]=='(') l++;
        else if(l==0) r++;
        else l--;
    }
    int rr = r;
    l = 0;
    r = 0;
    for(int i = n - 1; i >= 0; --i){
        if(s[i]==')') r++;
        else if(r==0) l++;
        else r--;
    }
    FOR(i,0,rr) s = '(' + s;
    FOR(i,0,l) s += ')';
    cout << s << endl;
}
