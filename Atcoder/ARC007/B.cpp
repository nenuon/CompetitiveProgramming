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

#define pb         push_back
#define mp         make_pair
#define ll         long long
#define PI         acos(-1.0)
#define ALL(A)     ((A).begin(), (A).end())
#define vsort(v)   sort(v.begin(),v.end())
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    int CD[100];
    int N,M,tmp;
    cin >> N >> M;
    FOR(i,0,101) CD[i]=i;
    FOR(i,0,M){
        cin >> tmp;
        FOR(j,1,N+1){
            if(CD[j]==tmp){
                swap(CD[0],CD[j]);
                break;
            }
        }
    }   
    FOR(i,1,N+1) cout << CD[i] << endl;
}