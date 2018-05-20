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
    int n;
    cin>>n;
    int min_amari = 999999999;
    //全探索
    for(int i=1; i<=sqrt(n); ++i){
        int w, h, amari;
        w = i;
        h = n / i;
        amari = n % i;
        min_amari=min(min_amari,abs(w-h)+amari);
    }
    cout<<min_amari<<endl;
}
