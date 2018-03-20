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
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;

class GreaterGame {
    public:
    double calc(vector<int> hand, vector<int> sothe) {
        int n=hand.size();
        bool used[2*n+1];
        CLR(used);
        sort(sothe.rbegin(),sothe.rend());
        sort(hand.begin(),hand.end());
        double win=0;
        FOR(i,0,n){
            if(sothe[i]==-1)break;
            FOR(j,0,n){
                if(!used[hand[j]]&&hand[j]>sothe[i]){
                    used[hand[j]]=true;
                    used[sothe[i]]=true;
                    win++;
                    break;
                }
                if(j==n-1){
                    used[sothe[i]]=true;
                    FOR(k,0,n){
                        if(!used[hand[k]]){
                            used[hand[k]]=true;
                            break;
                        }
                    }
                }
            }
        }
        vector<int> a,b;
        FOR(i,0,n){
            if(!used[hand[i]]){
                a.push_back(hand[i]);
                used[hand[i]]=true;
            }
        }
        FOR(i,1,2*n+1)if(!used[i])b.push_back(i);
        int m=a.size();
        // a[i]がかつ回数
        double winwin=0;
        FOR(i,0,m){
            double x=0;
            FOR(j,0,m){
                if(a[i]>b[j])x++;
            }
            winwin+=x;
        }
        return win+(m>0?winwin/m:0);
    }
};
