#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void){
    int i,a,N,hiku=0,cnt=0;
    int number[100000]={0};
    cin >> N;
    for(i=0;i<N;i++){
        cin >> a;
        number[a-1]++;
    }
    for(i=0;i<100000;i++){
        if(number[i]>=3){
            //hiku+=(number[i]/3)*2;
            //number[i]=number[i]/3+number[i]%3;
            while(1){
                hiku+=2;
                number[i]=number[i]-2;
                if(number[i]<3) break;
            }
        }
    }
    for(i=0;i<100000;i++){
        if(number[i]==2) cnt++;
    }

    cout << N-hiku-(cnt/2)*2-cnt%2*2 << endl;

    return 0;
}