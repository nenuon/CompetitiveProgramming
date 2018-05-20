#include <iostream>
#include <map>
using namespace std;
int main(){
    map<int, int> MAP;
    for(int i=0;i<3;++i){
        int a;
        cin>>a;
        MAP[a] = 1;
    }
    cout << MAP.size() << endl;
}
