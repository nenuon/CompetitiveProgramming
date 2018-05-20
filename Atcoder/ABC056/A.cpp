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

//H-そのまま
//D-逆

int main(){
    string a, b;
    cin>>a>>b;
    cout << (a[0]=='H'?b[0]:(b[0]=='H'?'D':'H')) << endl;
}
