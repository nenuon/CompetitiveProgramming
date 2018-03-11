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
#include <random>

using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
// 条件付き期待値E[X|Y] = 期待値 / Aliceが勝つ確率
double alice[55][2555], bob[55][2555];
class FixedDiceGameDiv1 {
    public:
    double getExpectation(int a, int b, int c, int d) {
        if(a * b <= c) return -1;
        alice[0][0] = bob[0][0] = 1.0;
        FOR(i,0,a) {
            FOR(j,0,a*b+1) {
                FOR(k,1,b+1) {
                    alice[i+1][j+k] += alice[i][j] / b;
                }
            }
        }
        FOR(i,0,c) {
            FOR(j,0,a*b+1) {
                FOR(k,1,d+1) {
                    bob[i+1][j+k] += bob[i][j] / d;
                }
            }
        }
        // Aliceスコアi、bobスコアj(<i)
        double x = 0.0, y = 0.0;
        FOR(i, a, a * b + 1) {
            FOR(j, c, c * d + 1) {
                if(i > j) {
                    x += i * alice[a][i] * bob[c][j]; // 期待値
                    y += alice[a][i] * bob[c][j]; // Aliceが勝つ確率
                }
            }
        }
        return x / y;
    }
};
