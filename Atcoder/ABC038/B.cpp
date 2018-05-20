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
    int W1,H1,W2,H2;
    cin>>W1>>H1>>W2>>H2;
    if(W1==W2 || W1==H2 || H1==W2 || H1==H2){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}
