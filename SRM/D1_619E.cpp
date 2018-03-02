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

class SplitStoneGame {
    public:
    string winOrLose(vector<int> number) {
        int n = number.size();
        bool lose = true;
        for(int i = 0; i < n; i ++) if(number[i] > 1) lose = false;
        if(lose || n < 3 || n % 2 == 0) return "LOSE";
        else return "WIN";
    }
};
