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

int main(){
    int a, b, n;
    cin>>a>>b>>n;
    FOR(i, n, n*a*b+1){
        if(i%a==0&&i%b==0){
            cout<<i<<endl;
            return 0;
        }
    }
}
