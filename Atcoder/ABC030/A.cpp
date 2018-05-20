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
    double A,B,C,D;
    cin>>A>>B>>C>>D;
    if(B/A>D/C) cout<<"TAKAHASHI"<<endl;
    else if(B/A<D/C) cout<<"AOKI"<<endl;
    else cout<<"DRAW"<<endl;
}
