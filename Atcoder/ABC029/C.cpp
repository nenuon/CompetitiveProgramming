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

//方針
//深さ優先dfsで
void dfs(string s, int nokori){
    if(nokori == 0) cout << s << endl;
    else{
        string s1 = s;
        string s2 = s;
        string s3 = s;
        s1.push_back('a');
        s2.push_back('b');
        s3.push_back('c');
        dfs(s1, nokori-1);
        dfs(s2, nokori-1);
        dfs(s3, nokori-1);
    }
}

int main(){
    int N;
    cin>>N;
    string s = "";
    dfs(s, N);
}
