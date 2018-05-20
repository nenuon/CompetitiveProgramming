#include<iostream>
#include<string>
using namespace std;

int main(void){
    int A, B;
    cin >> A >> B;
    if(A==B){
        cout << "Draw" << endl;
        return 0;
    }
    if((A==1 || A > B) && B!=1){
        cout << "Alice" << endl;
        return 0; 
    }
    if(B==1 || B > A){
        cout << "Bob" << endl;
        return 0;
    }
}