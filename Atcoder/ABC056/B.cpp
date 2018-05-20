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

int main(void){
    int W,a,b;
    cin>>W>>a>>b;
    //被ってる場合
    if((a+W>=b&&a<b+W) || (a<=b+W&&b<a+W)){
        cout << 0 << endl;
        return 0;
    }
    cout << (b>a+W?(b-a-W):(a-b-W)) << endl;
}
