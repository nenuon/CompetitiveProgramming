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
#include <string.h>
#include <vector>
using namespace std;
 
#define ll long long
 
#define FOR(i,a,b) for(int i = (a);i<(b);i++)
#define REP(i,a) FOR(i,0,(a))
#define MP make_pair

int main(void){
    int i,N,retu[1010],warareru,waru;
    long long int ans=1;
    cin >> N;
    for(i=0;i<1010;i++) retu[i]=1;
    for(i=2;i<=N;i++){
        warareru=i;
        waru=2;
        while(warareru!=1){
            if(warareru%waru==0) {
                retu[waru]++;
                warareru/=waru;
            }
            else waru++;
        }
    }
    FOR(i,0,1010){
        ans*=retu[i];
        ans=ans%1000000007;
    }
    printf("%.0lld\n",ans);
    return 0;
}