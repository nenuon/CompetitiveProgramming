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
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <typeinfo>
#include <fstream>
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
using namespace std;
//色々な属性の集合から、異なるものを２つずつペアにするには過半数を占める同一要素があってはならない
class HappyLetterDiv1 {
    public:
    string getHappyLetters(string letters) {
        string ans = "";
        int c[26];
        CLR(c);
        FOR(i,0,letters.size()) {
            c[letters[i]-'a']++;
        }
        // iを残せるかどうか
        FOR(i,0,26) {
            if(c[i] == 0) continue;
            priority_queue<int> Q;
            FOR(j,0,26) {
                if(i == j || c[j] == 0) continue;
                Q.push(c[j]);
            }
            while(Q.size() > 1) {
                int x = Q.top(); Q.pop();
                int y = Q.top(); Q.pop();
                x--;
                y--;
                if(x>0) Q.push(x);
                if(y>0) Q.push(y);
            }
            if(Q.empty() || c[i] > Q.top()) ans += char('a' + i);
        }
        return ans;
    }
};
