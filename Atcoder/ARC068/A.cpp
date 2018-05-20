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
#include <string.h>
#include <vector>
using namespace std;
 
#define ll long long
#define MP make_pair

int main(void){
    ll int x, ans=0, tmp;
    cin >> x;
    if(x%11==0) tmp=0;
    else if(x%11 >= 1 && x%11 <= 6) tmp=1;
    else tmp=2;
    cout << (x/11)*2+tmp << endl; 
    return 0;
}