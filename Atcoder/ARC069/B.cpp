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

int N;
string s;
int who[100010];

bool solve(int a, int b){
    who[0] = a;
    who[1] = b;
    FOR(k, 2, N){
        who[k] = (who[k-1] ^ (s[k-1] == 'o')) ? who[k-2] : 1 - who[k-2];
    }
    if ((who[N-2] ^ (who[0]) ^ (who[N-1]) ^ (s[N-1] == 'x'))) return false;
    if ((who[N-1] ^ who[1]) ^ (who[0] ^ (s[0] == 'x'))) return false; 
    return true;
}

int main(void){
    cin >> N;
    cin.ignore();
    getline(cin, s);
    bool check;
    if(solve(0, 0)) FOR(i, 0, N) cout << (who[i] ? "W" : "S");
    else if(solve(0, 1)) FOR(i, 0, N) cout << (who[i] ? "W" : "S");
    else if(solve(1, 0)) FOR(i, 0, N) cout << (who[i] ? "W" : "S");
    else if(solve(1, 1)) FOR(i, 0, N) cout << (who[i] ? "W" : "S");
    else cout << "-1";
    cout << endl;
}