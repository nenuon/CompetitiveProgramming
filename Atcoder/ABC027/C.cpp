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

//答え見た
//A->B->A->...とする
//Nの深さが偶数の時->Aはできるだけ大きい数, Bはできるだけ小さい数にしたい
//Nの深さが奇数の時は逆



int main(){
    ll N;
    ll dep;
    cin >> N;
    dep = 0;
    for(ll n = N;n > 0;){
        dep++;
        n /= 2;
    }
    //最初の人はできるだけ右に
    int who = 1;
    ll n = 1;
    if(dep%2==1){
        while(1){
            if(who==1) n = 2 * n + 1;
            else n *= 2;

            if(n > N){
                if(who==1){
                    cout << "Aoki" << endl;
                    break;
                }
                else{
                    cout << "Takahashi" << endl;
                    break;
                }
            }

            who *= -1;
        }
    }
    if(dep%2==0){
        while(1){
            if(who==1) n *= 2;
            else n = 2 * n + 1;

            if(n > N){
                if(who==1){
                    cout << "Aoki" << endl;
                    break;
                }
                else{
                    cout << "Takahashi" << endl;
                    break;
                }
            }
            who *= -1;
        }
    }
}
