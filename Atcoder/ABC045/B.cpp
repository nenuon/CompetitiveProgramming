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
    //0->aさん,1->bさん,2->cさん
    vector<string> vs(3);
    cin>>vs[0]>>vs[1]>>vs[2];
    //FOR(i, 0, 3) vs[i] += 'X';
    int n[3];
    FOR(i, 0, 3) n[i] = 0;
    n[0] = 1;
    int mozi = vs[0][0] - 'a';
    while(1){
        n[mozi]++;
        if(vs[mozi].length()+1==n[mozi]){
            cout << char('A' + mozi) << endl;
            return 0;
        }
        mozi = vs[mozi][n[mozi]-1] - 'a';
    }
}
