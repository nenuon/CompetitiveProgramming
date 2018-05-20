#include<iostream>
#include<string>
using namespace std;

int main(void){
    string str;
    getline(cin, str);
    str.replace(5,1," ");
    str.replace(13,1," ");
    cout << str << endl;
    return 0;
}