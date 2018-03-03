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
#define PI acos(-1)
using namespace std;

// O(10^8~9)くらいの解法
class RadioRange {
    public:
    double RadiusProbability(vector<int> X, vector<int> Y, vector<int> R, int Z) {
        int n = X.size();
        double a[n], b[n];
        for(int i = 0; i < n; i++) {
            double r;
            if(Y[i] == 0) {
                r = abs(X[i]);
            } else {
                double th = X[i] == 0 ? PI / 2 : atan((double)abs(Y[i]) / abs(X[i]));
                r = abs(Y[i]) / sin(th);
            }
            a[i] = max(0.0, r - R[i]);
            b[i] = r + R[i];
        }
        int MAX = 10000000;
        double ans = 0.000000000000;
        double dr = (double)Z / MAX;
        double i = 0.0;
        while(i < Z) {
            bool bad = false;
            for(int j = 0; j < n; j++) {
                if(i >= a[j] && i <= b[j]) {
                    bad = true;
                    break;
                }
            }
            if(!bad) ans += 1.0;
            i += dr;
        }
        return ans / MAX * 1.0000000000;
    }
};
