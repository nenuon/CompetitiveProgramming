#include <iostream>
using namespace std;
int dfs(int n){
    if(n==1) return 1;
    int ret = 1;
    ret = n + dfs(n-1);
    return ret;
}
int main(){
    int N;
    cin>>N;
    cout << dfs(N) << endl;
}
