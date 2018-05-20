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
    double n, m;
    cin>>n>>m;
    n = n>=12?n-12:n;
    n = n/12.0 * 360;
    n += 1/12.0 * m/60.0 * 360;//ちょっと進むやつ表現
    m = m/60.0 * 360;
    double MIN = 360;
    MIN = min(fabs(n-m),fabs(m-n));
    MIN = min(MIN, min(fabs(n-m+360),fabs(m-n+360)));
    printf("%.06lf\n", MIN);
}
