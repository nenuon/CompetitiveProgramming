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
    int A, B;
    cin >> A >> B;
    
    queue<int> q;
    q.push(A);

    map<int, int> hm;
    hm[A] = 0;

    int v[6] = {-10, -5, -1, 1, 5, 10};

    while(!q.empty() && !hm.count(B)){
        int now = q.front();q.pop();
        
        FOR(i, 0, 6){
            int next = now + v[i];

            if(hm.count(next)) continue;

            q.push(next);

            hm[next] = hm[now] + 1;
        }
    }
    cout << hm[B] << endl;
}