#include<iostream>
#include<cmath>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

int main(void){
    long long int i,N,A[100000],B[100000],ans=0;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> A[i] >> B[i];
    }
    for(i=N-1;i>=0;i--){
        if((A[i]+ans)%B[i]!=0){
            ans+=B[i]-(A[i]+ans)%B[i];
        }
    }
    cout << ans << endl;

    return 0;
}