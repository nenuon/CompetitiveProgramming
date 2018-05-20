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
    cout << ((A==1?14:A)>(B==1?14:B)?"Alice":"Bob") <<endl;
}
