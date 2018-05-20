#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(void){
    int N,M,l[300000]={0},r[300000]={0},i,j,k,ans=0,d;

    cin >> N >> M;
    for(i=0;i<N;i++){
        cin >> l[i] >> r[i];
    }
    for(i=1;i<=M;i++){
        ans=0;
        d=i;
        for(j=0;j<N/2;j++){
            while(d<=M){
                if(d>=l[j] && d<=r[j] && d>=l[N-j] && d<=r[N-j]){
                    ans+=2;
                    break;
                }
                else if((d>=l[j] && d<=r[j]) or (d>=l[N-j] && d<=r[N-j])){
                    ans++;
                    break;
                }
                d+=i;
            }
        }
        if(N%2==1 && d>=l[N/2+1] && d<=r[N/2+1]) ans++;
        cout << ans << endl;
    }

    return 0;
}