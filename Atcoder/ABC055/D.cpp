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

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

//羊0狼1
//○0×1
//動物とまるばつの情報のXORをみて0なら同じ、1なら違うとなる

int N;
int animal[100000];
int info[100000];

bool dfs(int animal1, int animal2, int n){
    animal[n-1]=animal1;
    animal[n]=animal2;
    if(n==N-1){
        if(((animal2^info[n])?animal1^1:animal1)!=animal[0]) return false;
        if(((animal[0]^info[0])?animal2^1:animal2)!=animal[1]) return false;
        return true;
    }
    return dfs(animal2,(animal2^info[n])?animal1^1:animal1,n+1);
}

int main(){
    cin>>N;
    string s;
    cin>>s;
    FOR(i, 0, N) info[i] = (s[i]=='o'?0:1);
    FOR(i, 0, 2){
        FOR(j, 0, 2){
            if(dfs(i,j,1)){
                FOR(k, 0, N) cout << (animal[k]==0?"S":"W");
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
