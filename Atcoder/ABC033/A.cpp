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
    int N;
    cin>>N;
    FOR(i, 1, 10){
        if(N%(1111*i)==0){
            cout << "SAME" << endl;
            return 0;
        }
    }
    cout << "DIFFERENT" << endl;
}
