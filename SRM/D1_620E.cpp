#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;
typedef pair<int, int> P;
set<P> SET;
class PairGame {
    void rec(int a, int b) {
        SET.insert(P(a, b));
        if(a > b) rec(a-b,b);
        else if(a < b) rec(a,b-a); 
    }
    int solve(int a, int b) {
        if(SET.count(P(a, b))) return a + b;
        if(a==b) return -1;
        else if(a > b) return solve(a-b,b);
        else return solve(a,b-a);
    }
    public:
    int maxSum(int a, int b, int c, int d) {
        rec(a, b);
        return solve(c, d);
    }
};
