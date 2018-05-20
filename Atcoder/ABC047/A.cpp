#include <iostream>
using namespace std;
//最大=その他の和
int main(){
    int a, b, c;
    cin>>a>>b>>c;
    if(a==b+c){
        cout << "Yes" << endl;
        return 0;
    }
    if(b==a+c){
        cout << "Yes" << endl;
        return 0;
    }
    if(c==b+a){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
