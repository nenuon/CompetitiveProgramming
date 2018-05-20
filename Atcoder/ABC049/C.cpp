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

//逆向きで考えると良い

int main(void){
    vector<string> vs(4);
    vs[0] = "maerd";
    vs[1] = "remaerd";
    vs[2] = "esare";
    vs[3] = "resare";
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string check = "";
    bool isFit = false;
    while(check.length()<s.length()){
        isFit = false;
        FOR(i, 0, 4){
            string ss = check + vs[i];
            if(ss.length()>s.length()) continue;
            if(ss==s.substr(0, ss.length())){
                check = ss;
                isFit = true;
                break;
            }
        }
        if(!isFit){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
