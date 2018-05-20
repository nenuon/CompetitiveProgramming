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

    int main(){
        string s;
        cin >> s;
        int ans = (int) 1e9;
        for (char c = 'a'; c <= 'z'; c++){
            string w = s;
            for (int it = 0; ; it++){
                if (w.empty()){
                    break;
                }
                if(w == string(w.length(), c)) {
                  ans = min(ans, it);
                  break;
                }
                string nw = "";
                for (int i = 0; i < (int) w.size() - 1; i++){
                    if (w[i] == c || w[i + 1] == c) {
                        nw += c;
                    } else {
                        nw += w[i];
                    }
                }
                w = nw;
            }
        }
        printf("%d\n", ans);
        return 0;
    }
