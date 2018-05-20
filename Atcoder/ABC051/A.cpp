#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;cin>>s;
    string::size_type pos = s.find(",");
    while(pos != string::npos){
        s.replace(pos, 1, " ");
        pos = s.find(",", pos + 1);
    }
    cout << s << endl;
}
