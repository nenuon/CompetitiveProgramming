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

void print(char s, int n){
    FOR(i, 0, n) cout << s;
}

int main(void){
    int sx, sy, tx, ty;
    cin>>sx>>sy>>tx>>ty;
    int dx = tx - sx;
    int dy = ty - sy;
    print('U', dy);
    print('R', dx);
    print('D', dy);
    print('L', dx+1);
    print('U', dy+1);
    print('R', dx+1);
    print('D', 1);
    print('R', 1);
    print('D', dy+1);
    print('L', dx+1);
    print('U', 1);
    cout << endl;
}
