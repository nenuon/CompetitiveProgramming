#include <iostream>
using namespace std;
int main(){
    int N,K,X,Y;
    cin>>N>>K>>X>>Y;
    cout << (N<=K?N*X:(X*K+(N-K)*Y)) << endl;
}
