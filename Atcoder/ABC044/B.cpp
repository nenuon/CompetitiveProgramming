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
    int mozi[26];
    FOR(i, 0, 26) mozi[i] = 0;
    string s;
    cin>>s;
    FOR(i, 0, s.length()) mozi[s[i]-'a']++;
    FOR(i, 0, 26){
        if(mozi[i]%2==1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
