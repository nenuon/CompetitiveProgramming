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
    ll N, A, B;
    cin >> N >> A >> B;
    if(A>B || (N==1 && A!=B)){
        cout << 0 << endl;
    }
    else if(N==1 || A==B){
        cout << 1 << endl;
    }
    else{
        cout << (B-A)*(N-1)+A-B+1 << endl;
    }
}
